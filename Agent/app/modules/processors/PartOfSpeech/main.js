/*
** PartOfSpeech
** Author: Mihai Polceanu, Daniel Rivero
** E-mail: mpolcean@cs.fiu.edu, drive076@fiu.edu
*/

/*****************************************************************\
** DummyCallbackPos
\*****************************************************************/

var PartOfSpeech = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "PartOfSpeech"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Processor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            R_CHARTEXT: 0,
            
            P_POS: 0
        };
        
        self.requiredResources[self.resourceNames.R_CHARTEXT] = new CharacterText();
        self.providedResources[self.resourceNames.P_POS] = new PosText();
    
        self.ttsUrl = "//affect.cs.fiu.edu:8080/StanfordNLP-0.1-dev/pos?text=";
        
        self.lastConvertedTextTimestamp = 0; //keep track of which was the last modification in input

    },
    
    getPos : function(event)
    {
        var self = this;        
        
        self.providedResources[self.resourceNames.P_POS].text = event.split(" ");
            
        for(i = 0; i < self.providedResources[self.resourceNames.P_POS].text.length; ++i)
        {
            jQuery(function($)
            {
                $.get(self.ttsUrl+ self.providedResources[self.resourceNames.P_POS].text[i], function(data)
                {
                    var split = data.split("_");
                    
                    self.providedResources[self.resourceNames.P_POS].pos.push(split[1]);                    
                });
            });
        }
    },
    
    run: function()
    {
        var self = this;    
        
        if(self.requiredResources[self.resourceNames.R_CHARTEXT].timeStamp > self.lastConvertedTextTimestamp)
        {           
            self.getPos(self.requiredResources[self.resourceNames.R_CHARTEXT].text);
            
            self.lastConvertedTextTimestamp = self.requiredResources[self.resourceNames.R_CHARTEXT].timeStamp;
        }     
        
    }
});
