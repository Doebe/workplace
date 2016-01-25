/*
** ChromeSpeech
** Author: Mihai Polceanu, Daniel Rivero
** E-mail: mpolcean@cs.fiu.edu, drive076@fiu.edu
*/

/*****************************************************************\
** Module proof of concept
\*****************************************************************/

/*
** Test module - inheriting from Module class
*/
var ChromeSpeech = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "ChromeSpeech"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Sensor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            P_USERTEXT: 0
        };
        
        self.providedResources[self.resourceNames.P_USERTEXT] = new UserText();
        
        self.lang = 'en-US';
        
        //detects if speech recognition is active or not
        self.recognizing = false;
        
        //container for returned string 
        self.final_transcript = " ";
        
        //Google speech API
        self.recognition = new webkitSpeechRecognition();
      
        //continuous print-stream
        //self.recognition.continuous = true;
        
        //display interimResults
        self.recognition.interimResults = true;
        
        //called when speech recognition starts
        self.recognition.onstart = self.onstart.bind(self);     
        
        //called when speach recognition finishes
        self.recognition.onend = self.onend.bind(self);
        
        //returns the results of speech recgonition
        self.recognition.onresult = self.onresult.bind(self);
        
        //for now only english
        self.recognition.lang = 'en-US';
        
        self.recognition.start();
    },
    
    onstart : function() {
        var self = this;
        self.recognizing = true;
        //$('start_img').src = 'mic-animate.gif';
        
        console.log("Speech Recognition: Started")

    },
    
    onend : function() {
        
        var self = this;
        
        self.recognition.start();
        
        console.log("Speech Recognition: Ended");
    },
    
    onresult : function(event) {
        
        var self = this;
        var interim_transcript = " ";
        
        //for every text returned from speech recognition
        for(var i = event.resultIndex; i < event.results.length; ++i)
        {
            //if there is no more text to be read
            if(event.results[i].isFinal)
            {
                //add it to final_transcript container
                self.final_transcript += " " + event.results[i][0].transcript;
                
                //testing for now
                var rightNow = Date.now();
                self.providedResources[self.resourceNames.P_USERTEXT].text = event.results[i][0].transcript;
                self.providedResources[self.resourceNames.P_USERTEXT].timeStamp = rightNow;
                
                console.log(event.results[i][0].transcript);
                console.log("User text: " + self.providedResources[self.resourceNames.P_USERTEXT].text);
            }
            else
            {
                //else add it to temporary container
                interim_transcript += event.results[i][0].transcript;
            }
        }
        
        //print results to console
        console.log("Interim Transcripts: " + interim_transcript);
        console.log("Final Transcripts: " + self.final_transcript);
    },
    
    run: function()
    {
       var self = this;

        
    }
});
