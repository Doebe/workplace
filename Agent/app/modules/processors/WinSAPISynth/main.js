/*
** Test module
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** Useful definitions
\*****************************************************************/

var Voice = Class.create
({
    initialize: function(name, gender, culture)
    {
        self.name = name;
        self.gender = gender;
        self.culture = culture;
    }
});

/*****************************************************************\
** Win SAPI Speech Synthesis
\*****************************************************************/

var WinSAPISynth = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "WinSAPISynth"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Processor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            R_CHARTEXT: 0,
            
            P_CHARSPEECH: 0
        };
        
        self.requiredResources[self.resourceNames.R_CHARTEXT] = new CharacterText();
        
        self.providedResources[self.resourceNames.P_CHARSPEECH] = new CharacterAudioStream();
        
        //this.providedResources.push(new FacialExpression()); //dummy
        
        //Speech server params
        self.ttsUrl = location.protocol+'//cognac.cis.fiu.edu/';
        self.serviceName = 'HapGLService.svc';
        
        //voice attributes
        self.voices = [];
        self.currentVoice = 3;
        
        self.lastConvertedTextTimestamp = 0; //keep track of which was the last modification in input
        
        //load voices
        jQuery(function($)
        {
            $.ajax({
                type: 'GET',
                url: self.ttsUrl + "/" + self.serviceName + "/getVoices"
            }).done(function(response) {
                var voices = JSON.parse(response).voices;
                $.each(voices, function(i, voice)
                {
                    self.voices.push(new Voice(voice.name, voice.gender, voice.culture));
                });
            });
        });
    },
    
    synthesize: function(text)
    {
        var self = this;
        
        jQuery(function($){
            $.ajax({
                type: 'GET',
                url: self.ttsUrl + "/" + self.serviceName + "/speak?text=" + encodeURI(text) + "&voice=" + encodeURI(self.voices[self.currentVoice])
            }).done(function(response) {
                var speechInfo = JSON.parse(response);		

                self.providedResources[self.resourceNames.P_CHARSPEECH].audioStream = (speechInfo.audioFormat + "," + speechInfo.audioStream);
                self.providedResources[self.resourceNames.P_CHARSPEECH].visemes = speechInfo.visemes;
                self.providedResources[self.resourceNames.P_CHARSPEECH].bookmarks = speechInfo.bookmarks;
                self.providedResources[self.resourceNames.P_CHARSPEECH].timeStamp = Date.now();
            });
        });
    },
    
    run: function()
    {
        var self = this;
        
        if (self.requiredResources[self.resourceNames.R_CHARTEXT].timeStamp > self.lastConvertedTextTimestamp)
        {
            //do synthesis
            self.synthesize(self.requiredResources[self.resourceNames.R_CHARTEXT].text);
            
            self.lastConvertedTextTimestamp = self.requiredResources[self.resourceNames.R_CHARTEXT].timeStamp;
        }
    }
});
