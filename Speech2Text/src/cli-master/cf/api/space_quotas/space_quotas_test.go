package space_quotas_test

import (
	"net/http"
	"net/http/httptest"
	"time"

	testapi "github.com/cloudfoundry/cli/cf/api/fakes"
	"github.com/cloudfoundry/cli/cf/configuration/core_config"
	"github.com/cloudfoundry/cli/cf/errors"
	"github.com/cloudfoundry/cli/cf/models"
	"github.com/cloudfoundry/cli/cf/net"
	testconfig "github.com/cloudfoundry/cli/testhelpers/configuration"
	testnet "github.com/cloudfoundry/cli/testhelpers/net"
	testterm "github.com/cloudfoundry/cli/testhelpers/terminal"

	. "github.com/cloudfoundry/cli/cf/api/space_quotas"
	. "github.com/cloudfoundry/cli/testhelpers/matchers"
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var _ = Describe("CloudControllerQuotaRepository", func() {
	var (
		testServer  *httptest.Server
		testHandler *testnet.TestHandler
		configRepo  core_config.ReadWriter
		repo        CloudControllerSpaceQuotaRepository
	)

	setupTestServer := func(reqs ...testnet.TestRequest) {
		testServer, testHandler = testnet.NewServer(reqs)
		configRepo.SetApiEndpoint(testServer.URL)
	}

	BeforeEach(func() {
		configRepo = testconfig.NewRepositoryWithDefaults()
		gateway := net.NewCloudControllerGateway(configRepo, time.Now, &testterm.FakeUI{})
		repo = NewCloudControllerSpaceQuotaRepository(configRepo, gateway)
	})

	AfterEach(func() {
		testServer.Close()
	})

	Describe("FindByName", func() {
		BeforeEach(func() {
			setupTestServer(firstSpaceQuotaRequest, secondSpaceQuotaRequest)
		})

		It("Finds Quota definitions by name", func() {
			quota, err := repo.FindByName("my-remote-quota")

			Expect(err).NotTo(HaveOccurred())
			Expect(testHandler).To(HaveAllRequestsCalled())
			Expect(quota).To(Equal(models.SpaceQuota{
				Guid:                    "my-quota-guid",
				Name:                    "my-remote-quota",
				MemoryLimit:             1024,
				RoutesLimit:             123,
				ServicesLimit:           321,
				NonBasicServicesAllowed: true,
				OrgGuid:                 "my-org-guid",
			}))
		})

		It("Returns an error if the quota cannot be found", func() {
			_, err := repo.FindByName("totally-not-a-quota")

			Expect(testHandler).To(HaveAllRequestsCalled())
			Expect(err.(*errors.ModelNotFoundError)).NotTo(BeNil())
		})
	})

	Describe("FindByOrg", func() {
		BeforeEach(func() {
			setupTestServer(firstSpaceQuotaRequest, secondSpaceQuotaRequest)
		})

		It("finds all quota definitions by org guid", func() {
			quotas, err := repo.FindByOrg("my-org-guid")

			Expect(err).NotTo(HaveOccurred())
			Expect(testHandler).To(HaveAllRequestsCalled())
			Expect(len(quotas)).To(Equal(3))
			Expect(quotas[0].Guid).To(Equal("my-quota-guid"))
			Expect(quotas[0].Name).To(Equal("my-remote-quota"))
			Expect(quotas[0].MemoryLimit).To(Equal(int64(1024)))
			Expect(quotas[0].RoutesLimit).To(Equal(123))
			Expect(quotas[0].ServicesLimit).To(Equal(321))
			Expect(quotas[0].OrgGuid).To(Equal("my-org-guid"))

			Expect(quotas[1].Guid).To(Equal("my-quota-guid2"))
			Expect(quotas[1].OrgGuid).To(Equal("my-org-guid"))
			Expect(quotas[2].Guid).To(Equal("my-quota-guid3"))
			Expect(quotas[2].OrgGuid).To(Equal("my-org-guid"))
		})
	})

	Describe("FindByGuid", func() {
		BeforeEach(func() {
			setupTestServer(firstSpaceQuotaRequest, secondSpaceQuotaRequest)
		})

		It("Finds Quota definitions by Guid", func() {
			quota, err := repo.FindByGuid("my-quota-guid")

			Expect(err).NotTo(HaveOccurred())
			Expect(testHandler).To(HaveAllRequestsCalled())
			Expect(quota).To(Equal(models.SpaceQuota{
				Guid:                    "my-quota-guid",
				Name:                    "my-remote-quota",
				MemoryLimit:             1024,
				RoutesLimit:             123,
				ServicesLimit:           321,
				NonBasicServicesAllowed: true,
				OrgGuid:                 "my-org-guid",
			}))
		})
		It("Returns an error if the quota cannot be found", func() {
			_, err := repo.FindByGuid("totally-not-a-quota-guid")

			Expect(testHandler).To(HaveAllRequestsCalled())
			Expect(err.(*errors.ModelNotFoundError)).NotTo(BeNil())
		})
	})

	Describe("AssociateSpaceWithQuota", func() {
		It("sets the quota for a space", func() {
			req := testapi.NewCloudControllerTestRequest(testnet.TestRequest{
				Method:   "PUT",
				Path:     "/v2/space_quota_definitions/my-quota-guid/spaces/my-space-guid",
				Response: testnet.TestResponse{Status: http.StatusCreated},
			})

			setupTestServer(req)

			err := repo.AssociateSpaceWithQuota("my-space-guid", "my-quota-guid")
			Expect(testHandler).To(HaveAllRequestsCalled())
			Expect(err).NotTo(HaveOccurred())
		})
	})

	Describe("UnassignQuotaFromSpace", func() {
		It("deletes the association between the quota and the space", func() {
			req := testapi.NewCloudControllerTestRequest(testnet.TestRequest{
				Method:   "DELETE",
				Path:     "/v2/space_quota_definitions/my-quota-guid/spaces/my-space-guid",
				Response: testnet.TestResponse{Status: http.StatusNoContent},
			})
			setupTestServer(req)

			err := repo.UnassignQuotaFromSpace("my-space-guid", "my-quota-guid")
			Expect(err).NotTo(HaveOccurred())
			Expect(testHandler).To(HaveAllRequestsCalled())
		})
	})

	Describe("Create", func() {
		It("creates a new quota with the given name", func() {
			req := testapi.NewCloudControllerTestRequest(testnet.TestRequest{
				Method: "POST",
				Path:   "/v2/space_quota_definitions",
				Matcher: testnet.RequestBodyMatcher(`{
					"name": "not-so-strict",
					"non_basic_services_allowed": false,
					"total_services": 1,
					"total_routes": 12,
					"memory_limit": 123,
					"instance_memory_limit": 0,
					"organization_guid": "my-org-guid"
				}`),
				Response: testnet.TestResponse{Status: http.StatusCreated},
			})
			setupTestServer(req)

			quota := models.SpaceQuota{
				Name:          "not-so-strict",
				ServicesLimit: 1,
				RoutesLimit:   12,
				MemoryLimit:   123,
				OrgGuid:       "my-org-guid",
			}
			err := repo.Create(quota)
			Expect(err).NotTo(HaveOccurred())
			Expect(testHandler).To(HaveAllRequestsCalled())
		})
	})

	Describe("Update", func() {
		It("updates an existing quota", func() {
			setupTestServer(testapi.NewCloudControllerTestRequest(testnet.TestRequest{
				Method: "PUT",
				Path:   "/v2/space_quota_definitions/my-quota-guid",
				Matcher: testnet.RequestBodyMatcher(`{
					"guid": "my-quota-guid",
					"non_basic_services_allowed": false,
					"name": "amazing-quota",
					"total_services": 1,
					"total_routes": 12,
					"memory_limit": 123,
					"instance_memory_limit": 1234,
					"organization_guid": "myorgguid"
				}`),
			}))

			quota := models.SpaceQuota{
				Guid: "my-quota-guid",
				Name: "amazing-quota",
				NonBasicServicesAllowed: false,
				ServicesLimit:           1,
				RoutesLimit:             12,
				MemoryLimit:             123,
				InstanceMemoryLimit:     1234,
				OrgGuid:                 "myorgguid",
			}

			err := repo.Update(quota)
			Expect(err).NotTo(HaveOccurred())
			Expect(testHandler).To(HaveAllRequestsCalled())
		})
	})

	Describe("Delete", func() {
		It("deletes the quota with the given name", func() {
			req := testapi.NewCloudControllerTestRequest(testnet.TestRequest{
				Method:   "DELETE",
				Path:     "/v2/space_quota_definitions/my-quota-guid",
				Response: testnet.TestResponse{Status: http.StatusNoContent},
			})
			setupTestServer(req)

			err := repo.Delete("my-quota-guid")
			Expect(err).NotTo(HaveOccurred())
			Expect(testHandler).To(HaveAllRequestsCalled())
		})
	})
})

var firstQuotaRequest = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method: "GET",
	Path:   "/v2/space_quota_definitions",
	Response: testnet.TestResponse{
		Status: http.StatusOK,
		Body: `{
		"next_url": "/v2/quota_definitions?page=2",
		"resources": [
			{
			  "metadata": { "guid": "my-quota-guid" },
			  "entity": {
			  	"name": "my-remote-quota",
			  	"memory_limit": 1024,
			  	"total_routes": 123,
			  	"total_services": 321,
			  	"non_basic_services_allowed": true,
			  }
			}
		]}`,
	},
})

var secondQuotaRequest = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method: "GET",
	Path:   "/v2/space_quota_definitions?page=2",
	Response: testnet.TestResponse{
		Status: http.StatusOK,
		Body: `{
		"resources": [
			{
			  "metadata": { "guid": "my-quota-guid2" },
			  "entity": { "name": "my-remote-quota2", "memory_limit": 1024 }
			},
			{
			  "metadata": { "guid": "my-quota-guid3" },
			  "entity": { "name": "my-remote-quota3", "memory_limit": 1024 }
			}
		]}`,
	},
})

var firstSpaceQuotaRequest = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method: "GET",
	Path:   "/v2/organizations/my-org-guid/space_quota_definitions",
	Response: testnet.TestResponse{
		Status: http.StatusOK,
		Body: `{
		"next_url": "/v2/organizations/my-org-guid/space_quota_definitions?page=2",
		"resources": [
			{
			  "metadata": { "guid": "my-quota-guid" },
			  "entity": {
			  	"name": "my-remote-quota",
			  	"memory_limit": 1024,
			  	"total_routes": 123,
			  	"total_services": 321,
			  	"non_basic_services_allowed": true,
			  	"organization_guid": "my-org-guid"
			  }
			}
		]}`,
	},
})

var secondSpaceQuotaRequest = testapi.NewCloudControllerTestRequest(testnet.TestRequest{
	Method: "GET",
	Path:   "/v2/organizations/my-org-guid/space_quota_definitions?page=2",
	Response: testnet.TestResponse{
		Status: http.StatusOK,
		Body: `{
		"resources": [
			{
			  "metadata": { "guid": "my-quota-guid2" },
			  "entity": { "name": "my-remote-quota2", "memory_limit": 1024, "organization_guid": "my-org-guid" }
			},
			{
			  "metadata": { "guid": "my-quota-guid3" },
			  "entity": { "name": "my-remote-quota3", "memory_limit": 1024, "organization_guid": "my-org-guid" }
			}
		]}`,
	},
})
