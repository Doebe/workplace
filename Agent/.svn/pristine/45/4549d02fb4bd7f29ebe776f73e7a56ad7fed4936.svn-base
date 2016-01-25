/*
** DummyCharacterAudioStreamProvider
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** DummyEmotionStateProvider
\*****************************************************************/

var DummyCharacterAudioStreamProvider = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "DummyCharacterAudioStreamProvider"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Dummy; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.providedResources.push(new CharacterAudioStream()); //dummy
    },
    
    run: function()
    {
        //do nothing
    }
});
