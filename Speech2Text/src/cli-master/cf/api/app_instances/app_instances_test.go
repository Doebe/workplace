package app_instances_test

import (
	"net/http"
	"net/http/httptest"
	"time"

	testapi "github.com/cloudfoundry/cli/cf/api/fakes"
	"github.com/cloudfoundry/cli/cf/models"
	"github.com/cloudfoundry/cli/cf/net"
	testconfig "github.com/cloudfoundry/cli/testhelpers/configuration"
	testnet "github.com/cloudfoundry/cli/testhelpers/net"
	testterm "github.com/cloudfoundry/cli/testhelpers/terminal"

	. "github.com/cloudfoundry/cli/cf/api/app_instances"
	. "github.com/cloudfoundry/cli/testhelpers/matchers"
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var _ = Describe("AppInstancesRepo", func() {
	Describe("Getting the instances for an application", func() {
		It("returns instances of the app, given a guid", func() {
			ts, handler, repo := createAppInstancesRepo([]testnet.TestRequest{
				appInstancesRequest,
				appStatsRequest,
			})
			defer ts.Close()
			appGuid := "my-cool-app-guid"

			instances, err := repo.GetInstances(appGuid)
			Expect(err).NotTo(HaveOccurred())
			Expect(handler).To(HaveAllRequestsCalled())

			Expect(len(instances)).To(Equal(2))

			Expect(instances[0].State).To(Equal(models.InstanceRunning))
			Expect(instances[1].State).To(Equal(models.InstanceStarting))
			Expect(instances[1].Details).To(Equal("insufficient resources"))

			instance0 := instances[0]
			Expect(instance0.Since).To(Equal(time.Unix(1379522342, 0)))
			Expect(instance0.DiskQuota).To(Equal(int64(1073741824)))
			Expect(instance0.DiskUsage).To(Equal(int64(56037376)))
			Expect(instance0.MemQuota).To(Equal(int64(67108864)))
			Expect(instance0.MemUsage).To(Equal(int64(19218432)))
			Expect(instance0.CpuUsage).To(Equal(3.659571249238058e-05))
		})
	})

	Describe("Deleting an instance for an application", func() {
		It("returns no error if the response is successful", func() {
			ts, handler, repo := createAppInstancesRepo([]testnet.TestRequest{
				deleteInstanceRequest,
			})
			defer ts.Close()
			appGuid := "my-cool-app-guid"

			err := repo.DeleteInstance(appGuid, 0)
			Expect(err).NotTo(HaveOccurred())
			Expect(handler).To(HaveAllRequestsCalled())
		})

		It("returns the error if the response is unsuccessful", func() {
			ts, handler, repo := createAppInstancesRepo([]testnet.TestRequest{
				deleteInstanceFromUnkownApp,
			})
			defer ts.Close()
			appGuid := "some-wrong-app-guid"

			err := repo.DeleteInstance(appGuid, 0)
			Expect(err).To(HaveOccurred())
			Expect(handler).To(HaveAllRequestsCalled())

		})
	})
})

var appStatsRequest = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method: "GET",
	Path:   "/v2/apps/my-cool-app-guid/stats",
	Response: testnet.TestResponse{Status: http.StatusOK, Body: `
{
  "1":{
    "stats": {
        "disk_quota": 10000,
        "mem_quota": 1024,
        "usage": {
            "cpu": 0.3,
            "disk": 10000,
            "mem": 1024
        }
    }
  },
  "0":{
    "stats": {
        "disk_quota": 1073741824,
        "mem_quota": 67108864,
        "usage": {
            "cpu": 3.659571249238058e-05,
            "disk": 56037376,
            "mem": 19218432
        }
    }
  }
}`}})

var appInstancesRequest = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method: "GET",
	Path:   "/v2/apps/my-cool-app-guid/instances",
	Response: testnet.TestResponse{Status: http.StatusOK, Body: `
{
  "1": {
    "state": "STARTING",
    "details": "insufficient resources",
    "since": 1379522342.6783738
  },
  "0": {
    "state": "RUNNING",
    "since": 1379522342.6783738
  }
}`}})

var deleteInstanceRequest = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method:   "DELETE",
	Path:     "/v2/apps/my-cool-app-guid/instances/0",
	Response: testnet.TestResponse{Status: http.StatusNoContent, Body: `{}`},
})

var deleteInstanceFromUnkownApp = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method:   "DELETE",
	Path:     "/v2/apps/some-wrong-app-guid/instances/0",
	Response: testnet.TestResponse{Status: http.StatusNotFound, Body: `{}`},
})

func createAppInstancesRepo(requests []testnet.TestRequest) (ts *httptest.Server, handler *testnet.TestHandler, repo AppInstancesRepository) {
	ts, handler = testnet.NewServer(requests)
	space := models.SpaceFields{}
	space.Guid = "my-space-guid"
	configRepo := testconfig.NewRepositoryWithDefaults()
	configRepo.SetApiEndpoint(ts.URL)
	gateway := net.NewCloudControllerGateway(configRepo, time.Now, &testterm.FakeUI{})
	repo = NewCloudControllerAppInstancesRepository(configRepo, gateway)
	return
}
