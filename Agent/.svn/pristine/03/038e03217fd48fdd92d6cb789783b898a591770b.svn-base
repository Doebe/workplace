/*
** DummyEmotionStateProvider
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** DummyEmotionStateProvider
\*****************************************************************/

var DummyEmotionStateProvider = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "DummyEmotionStateProvider"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Sensor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.providedResources.push(new CharacterFacialExpression()); //dummy
    },
    
    run: function()
    {
        //do nothing
    }
});
