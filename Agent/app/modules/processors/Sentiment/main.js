/*
** Sentiment
** Author: Mihai Polceanu, Daniel Rivero
** E-mail: mpolcean@cs.fiu.edu, drive076@fiu.edu
*/

/*****************************************************************\
** DummyCallbackPos
\*****************************************************************/

var Sentiment = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "Sentiment"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Processor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            R_CHARTEXT: 0,
            
            P_SENTIMENT: 0
        };
        
        self.requiredResources[self.resourceNames.R_CHARTEXT] = new CharacterText();
        self.providedResources[self.resourceNames.P_SENTIMENT] = new SentimentText();
    
        self.ttsUrl = "//affect.cs.fiu.edu:8080/StanfordNLP-0.1-dev/sentiment?text=";
        
        self.lastConvertedTextTimestamp = 0; //keep track of which was the last modification in input

    },
    
    getSentiment : function(text)
    {
        var self = this;           
       
        jQuery(function($)
        {
            $.get(self.ttsUrl+ text, function(data)
            {
                var split = data.split(text);             
                
                self.providedResources[self.resourceNames.P_SENTIMENT].sentiment.push(split[0]);
                
            });
        });       
    },
    
    run: function()
    {
        var self = this;    
        
        if(self.requiredResources[self.resourceNames.R_CHARTEXT].timeStamp > self.lastConvertedTextTimestamp)
        {           
            self.getSentiment(self.requiredResources[self.resourceNames.R_CHARTEXT].text);
            
            self.lastConvertedTextTimestamp = self.requiredResources[self.resourceNames.R_CHARTEXT].timeStamp;
        } 
    }
});
