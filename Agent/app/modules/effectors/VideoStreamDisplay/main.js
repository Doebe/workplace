/*
** Test module
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** VideoStreamDisplay
\*****************************************************************/

var VideoStreamDisplay = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "VideoStreamDisplay"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Effector; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.requiredResourceNames = {
            VIDEOSTREAM: 0
        };
        
        self.requiredResources[self.requiredResourceNames.VIDEOSTREAM] = new VideoStream();
    },
    
    run: function()
    {
        var self = this;
        
        if (self.active)
        {
            var video = document.querySelector('#videoel');
            
            if ((video.paused || video.srcObject === undefined || video.srcObject === null) && self.requiredResources[self.requiredResourceNames.VIDEOSTREAM].videoStream != null)
            {
                video.srcObject = self.requiredResources[self.requiredResourceNames.VIDEOSTREAM].videoStream;
                
                video.play();
            }
        }
        else
        {
            var video = document.querySelector('#videoel');
            video.pause();
        }
    }
});