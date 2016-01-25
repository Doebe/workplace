/*
** Module containing clmtrackr by Audun Mathias Øygard - https://github.com/auduno/clmtrackr
** Module author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** Clmtrackr emotion recognition module
\*****************************************************************/

var ClmTrackr = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "ClmTrackr";
        self.type = ModuleType.Processor;
        self.mandatory = false;
        
        self.resourceNames = {
            R_VIDEOSTREAM: 0,
            
            P_USERFACIALEXPRESSION: 0
        };
        
        self.requiredResources[self.resourceNames.R_VIDEOSTREAM] = new VideoStream();
        
        self.providedResources[self.resourceNames.P_USERFACIALEXPRESSION] = new UserFacialExpression();
        
        //---------//
        
        self.vid = document.createElement('video');
        var attWidth = document.createAttribute("width");
        attWidth.value = "300";
        self.vid.setAttributeNode(attWidth);
        var attWidth = document.createAttribute("height");
        attWidth.value = "250";
        self.vid.setAttributeNode(attWidth);
        
        //initialize clmtrackr
        self.ctrack = new clm.tracker({useWebGL : true});
        
        self.ctrack.init(pModel);
        
        self.ec = new emotionClassifier();
        self.ec.init(emotionModel);
    },
    
    run: function()
    {
        var self = this;
        
        if (self.active)
        {
            if ((self.vid.paused || self.vid.srcObject === undefined || self.vid.srcObject === null) && self.requiredResources[self.resourceNames.R_VIDEOSTREAM].videoStream != null)
            {
                self.vid.srcObject = self.requiredResources[self.resourceNames.R_VIDEOSTREAM].videoStream;
                
                // start video
                self.vid.play();

                // start tracking
                self.ctrack.start(self.vid);
            }
        }
        else
        {
            self.ctrack.stop();
            self.vid.pause();
        }
        
        var cp = self.ctrack.getCurrentParameters();

        var er = self.ec.meanPredict(cp);
        if (er)
        {
            self.providedResources[self.resourceNames.P_USERFACIALEXPRESSION].data[Emotion.Anger] = er[0].value;
            self.providedResources[self.resourceNames.P_USERFACIALEXPRESSION].data[Emotion.Sadness] = er[1].value;
            self.providedResources[self.resourceNames.P_USERFACIALEXPRESSION].data[Emotion.Surprise] = er[2].value;
            self.providedResources[self.resourceNames.P_USERFACIALEXPRESSION].data[Emotion.Happiness] = er[3].value;
            
            //console.log(er[0].value+" "+er[1].value+" "+er[2].value+" "+er[3].value);
        }
    }
});

var ClmTrackrWithOverlay = Class.create(ClmTrackr,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "ClmTrackrWithOverlay";
        
        self.overlay = document.getElementById('videoel-overlay');
        self.overlayCC = self.overlay.getContext('2d');
    },
    
    run: function($super)
    {
        var self = this;
        
        $super();
        
        self.overlayCC.clearRect(0, 0, 300, 250);
        //psrElement.innerHTML = "score :" + ctrack.getScore().toFixed(4);
        if (self.ctrack.getCurrentPosition())
        {
            self.ctrack.draw(self.overlay);
        }
    }
});