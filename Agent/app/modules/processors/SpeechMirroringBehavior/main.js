/*
** SpeechMirroringBehavior module
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** SpeechMirroringBehavior module
\*****************************************************************/

var SpeechMirroringBehavior = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "SpeechMirroringBehavior"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Processor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            R_USERTEXT: 0,
            
            P_CHARTEXT: 0
        };
        
        self.requiredResources[self.resourceNames.R_USERTEXT] = new UserText(); //dummy
        
        self.providedResources[self.resourceNames.P_CHARTEXT] = new CharacterText();
        
    },
    
    run: function()
    {
        var self = this;
        
        self.providedResources[self.resourceNames.P_CHARTEXT].text = self.requiredResources[self.resourceNames.R_USERTEXT].text;
        self.providedResources[self.resourceNames.P_CHARTEXT].timeStamp = self.requiredResources[self.resourceNames.R_USERTEXT].timeStamp;
    }
});
