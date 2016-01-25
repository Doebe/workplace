package configuration

import (
	"github.com/cloudfoundry/cli/cf/configuration"
	"github.com/cloudfoundry/cli/cf/configuration/core_config"
)

type FakePersistor struct {
	LoadReturns struct {
		Data *core_config.Data
		Err  error
	}

	SaveArgs struct {
		Data *core_config.Data
	}
	SaveReturns struct {
		Err error
	}
}

func NewFakePersistor() *FakePersistor {
	return &FakePersistor{}
}

func (fp *FakePersistor) Load(data configuration.DataInterface) error {
	if fp.LoadReturns.Data == nil {
		fp.LoadReturns.Data = core_config.NewData()
	}
	return fp.LoadReturns.Err
}

func (fp *FakePersistor) Delete() {}

func (fp *FakePersistor) Exists() bool {
	return true
}

func (fp *FakePersistor) Save(data configuration.DataInterface) (err error) {
	fp.SaveArgs.Data = data.(*core_config.Data)
	err = fp.SaveReturns.Err
	return
}
