package net_test

import (
	"fmt"
	"net/http"
	"net/http/httptest"
	"time"

	"github.com/cloudfoundry/cli/cf/configuration/core_config"
	"github.com/cloudfoundry/cli/cf/errors"
	. "github.com/cloudfoundry/cli/cf/net"
	testconfig "github.com/cloudfoundry/cli/testhelpers/configuration"
	testterm "github.com/cloudfoundry/cli/testhelpers/terminal"
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var failingCloudControllerRequest = func(writer http.ResponseWriter, request *http.Request) {
	writer.WriteHeader(http.StatusBadRequest)
	jsonResponse := `{ "code": 210003, "description": "The host is taken: test1" }`
	fmt.Fprintln(writer, jsonResponse)
}

var invalidTokenCloudControllerRequest = func(writer http.ResponseWriter, request *http.Request) {
	writer.WriteHeader(http.StatusBadRequest)
	jsonResponse := `{ "code": 1000, "description": "The token is invalid" }`
	fmt.Fprintln(writer, jsonResponse)
}

var _ = Describe("Cloud Controller Gateway", func() {
	var gateway Gateway
	var config core_config.Reader

	BeforeEach(func() {
		config = testconfig.NewRepository()
		gateway = NewCloudControllerGateway(config, time.Now, &testterm.FakeUI{})
	})

	It("parses error responses", func() {
		ts := httptest.NewTLSServer(http.HandlerFunc(failingCloudControllerRequest))
		defer ts.Close()
		gateway.SetTrustedCerts(ts.TLS.Certificates)

		request, apiErr := gateway.NewRequest("GET", ts.URL, "TOKEN", nil)
		_, apiErr = gateway.PerformRequest(request)

		Expect(apiErr).NotTo(BeNil())
		Expect(apiErr.Error()).To(ContainSubstring("The host is taken: test1"))
		Expect(apiErr.(errors.HttpError).ErrorCode()).To(ContainSubstring("210003"))
	})

	It("parses invalid token responses", func() {
		ts := httptest.NewTLSServer(http.HandlerFunc(invalidTokenCloudControllerRequest))
		defer ts.Close()
		gateway.SetTrustedCerts(ts.TLS.Certificates)

		request, apiErr := gateway.NewRequest("GET", ts.URL, "TOKEN", nil)
		_, apiErr = gateway.PerformRequest(request)

		Expect(apiErr).NotTo(BeNil())
		Expect(apiErr.Error()).To(ContainSubstring("The token is invalid"))
		Expect(apiErr.(*errors.InvalidTokenError)).To(HaveOccurred())
	})
})
