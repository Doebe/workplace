/*
** DummyEmotionStateProvider
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** DummyCharacterTextProvider
\*****************************************************************/

var DummyCharacterTextProvider = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "DummyCharacterTextProvider"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Sensor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.providedResources.push(new CharacterText()); //dummy
        
        self.vocabulary = ["Hello there.", "I can speak.", "Do you like it ?", "Yahoo !"];
        self.currentWord = 0;
        self.lastTime = Date.now();
    },
    
    run: function()
    {
        var self = this;
        
        var rightNow = Date.now();
        if (rightNow - self.lastTime > 3000)
        {
            self.providedResources[0].text = self.vocabulary[self.currentWord];
            self.providedResources[0].timeStamp = rightNow;
            
            self.currentWord++;
            if (self.currentWord >= self.vocabulary.length) self.currentWord = 0;
            
            self.lastTime = rightNow;
        }
    }
});
