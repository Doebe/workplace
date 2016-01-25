package copy_application_source_test

import (
	"github.com/cloudfoundry/cli/cf/i18n"
	"github.com/cloudfoundry/cli/testhelpers/configuration"
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"

	"testing"
)

func TestCopyApplicationSource(t *testing.T) {
	config := configuration.NewRepositoryWithDefaults()
	i18n.T = i18n.Init(config)

	RegisterFailHandler(Fail)
	RunSpecs(t, "CopyApplicationSource Suite")
}
