/*
** WebGLScene module - adapted from original code by Guido Ruiz & ??
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** HapCharacter
\*****************************************************************/

var HapCharacter = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "HapCharacter"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Processor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            R_CHARFACIALEXPRESSION: 0,
            R_CHARSPEECH: 1,
            
            P_CHARMESH: 0
        };
        
        self.requiredResources[self.resourceNames.R_CHARFACIALEXPRESSION] = new CharacterFacialExpression();
        self.requiredResources[self.resourceNames.R_CHARSPEECH] = new CharacterAudioStream();
        self.providedResources[self.resourceNames.P_CHARMESH] = new Mesh3D();
        
        self.animationMixer = null;
        self.animations = [];
        
        //speech
        self.visemeIndex = -1;
        self.isSpeaking = false;
        self.lastSpoke = 0;
        self.talkInitTime = null;
        
        self.textureLoader = new THREE.TextureLoader();
        self.jsonLoader = new THREE.JSONLoader();
        
        self.clock = new THREE.Clock();
        
        self.load();
    },
    
    load: function()
    {
        var self = this;
        
        self.jsonLoader.load(self.url+"/"+self.fileName+".json", function(geometry, materials)
        {
            materials[0].skinning = true;

            materials[0].morphTargets = true;
            materials[0].map = self.textureLoader.load(self.url+"/"+self.fileName+".png");
            
            
            self.providedResources[self.resourceNames.P_CHARMESH].mesh = new THREE.SkinnedMesh( geometry, new THREE.MeshFaceMaterial( materials ) );
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.position.set(0, 0, 10);
            //self.mesh.scale.set( s, s, s );
            
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.castShadow = true;
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.receiveShadow = true;
            
            //loads the different animations into the animations array
            for(var i = 0; i < geometry.animations.length; ++i)
            {
                //THREE.AnimationHandler.add( geometry.animations[ i ] );
                var animName = geometry.animations[i].name;
                self.animations[animName] = new THREE.AnimationAction( geometry.animations[i] );
            }
            
            //var clipMorpher = THREE.AnimationClip.CreateFromMorphTargetSequence( 'facialExpressions', mesh.geometry.morphTargets, 3 );
            
            self.animationMixer = new THREE.AnimationMixer( self.providedResources[self.resourceNames.P_CHARMESH].mesh );
            //mixer.addAction( new THREE.AnimationAction( clipMorpher ) );
            self.animationMixer.addAction( self.animations['RightHandMove'] );
            //self.animationMixer.addAction( self.animations['RightHandMove'] ); //for some reason, running the same animation twice increases the speed...
            
            
            self.providedResources[self.resourceNames.P_CHARMESH].pending = false;
            self.providedResources[self.resourceNames.P_CHARMESH].visible = true;
        });
    },
    
    emHappiness: function (intensity)
    {
        var self = this;
        if (self.providedResources[self.resourceNames.P_CHARMESH].mesh)
        {
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.morphTargetInfluences[48] = intensity;
        }
    },

    emSadness: function (intensity)
    {
        var self = this;
        if (self.providedResources[self.resourceNames.P_CHARMESH].mesh)
        {
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.morphTargetInfluences[49] = intensity;
        }
    },

    emSurprise: function (intensity)
    {
        var self = this;
        if (self.providedResources[self.resourceNames.P_CHARMESH].mesh)
        {
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.morphTargetInfluences[50] = intensity;
        }
    },

    emAnger: function (intensity)
    {
        var self = this;
        if (self.providedResources[self.resourceNames.P_CHARMESH].mesh)
        {
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.morphTargetInfluences[53] = intensity;
        }
    },

    emFear: function (intensity)
    {
        var self = this;
        if (self.providedResources[self.resourceNames.P_CHARMESH].mesh)
        {
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.morphTargetInfluences[51] = intensity;
        }
    },

    emDisgust: function (intensity)
    {
        var self = this;
        if (self.providedResources[self.resourceNames.P_CHARMESH].mesh)
        {
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.morphTargetInfluences[52] = intensity;
        }
    },

    setMorphTargetInfluence: function (index, intensity)
    {
        var self = this;
        if (self.providedResources[self.resourceNames.P_CHARMESH].mesh)
        {
            self.providedResources[self.resourceNames.P_CHARMESH].mesh.morphTargetInfluences[index] = intensity;
        }
    },
    
    /*
    renderViseme: function ()
    {
        if (self.visemeIndex >= 0)
        {
            // then is speaking
            var now = Date.now();
            var talkElapsed = now - self.talkInitTime;
            var viseme = self.visemes[self.visemeIndex];
            var nextViseme = self.visemes[self.visemeIndex + 1];
            var visemeElapsed = talkElapsed - viseme.audioPosition;
            
            if (talkElapsed < viseme.audioPosition) return;
            
            if (visemeElapsed < viseme.duration)
            {
                // still in current viseme
                increment = visemeElapsed / viseme.duration;

                if (!nextViseme || (viseme.number != nextViseme.number))
                {
                    // then need to transition visemes
                    if (self.visemeIndex > 0)
                    {
                        // fade out current viseme
                        var morphInfluenceIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[viseme.number + ''].name];
                        self.mesh.morphTargetInfluences[morphInfluenceIndex] = 1 - increment;
                    }

                    if (nextViseme)
                    {
                        // fade in next viseme
                        var nextVisemeMorphIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[nextViseme.number + ''].name];
                        self.mesh.morphTargetInfluences[nextVisemeMorphIndex] = increment;
                    }
                }
            }
            else
            {
                // it's time to render next viseme
                var morphInfluenceIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[viseme.number + ''].name];
                self.mesh.morphTargetInfluences[morphInfluenceIndex] = 0;

                if (nextViseme)
                {
                    var nextVisemeMorphIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[nextViseme.number + ''].name];
                    self.mesh.morphTargetInfluences[nextVisemeMorphIndex] = 1;

                    self.visemeIndex++;
                }
                else
                {
                    // stop talking
                    if(bookmarks.length > 0) self.setEmotion(bookmarks[bookmarks.length-1].name, 0);

                    self.isSpeaking = false;
                    self.visemeIndex = -1;
                    self.talkInitTime = null;

                    if (_endSpeakCallback && typeof _endSpeakCallback == 'function') _endSpeakCallback();
                }
            }
        }
    }
    */
    
    speak: function(src)
    {
        var self = this;
        
        var df = document.createDocumentFragment();
        var audioStarted;

        var snd = new Audio(src);
        df.appendChild(snd); // keep in fragment until finished playing
        
        snd.addEventListener('ended', function () {
            df.removeChild(snd);
            self.isSpeaking = false;
            // TODO: remove this, just for testing
            console.log('audio (ms): ' + (Date.now() - audioStarted));
        });

        snd.addEventListener('play', function ()
        {
            /*
            bookmarkIndex = 0;
            lastBookmark = bookmarks.length;
            console.log('Bookmark index is ' + lastBookmark + ' and the length of bookmarks is ' + lastBookmark);
            
            self.visemeIndex = 0;
            */
            
            self.talkInitTime = Date.now();
            self.visemeIndex = 0;
            self.isSpeaking = true;
            audioStarted = Date.now();
        });

        snd.play();
        //return snd;
    },
    
    run: function() //delta
    {
        var self = this;
        
        var delta = self.clock.getDelta();
        
        if (self.requiredResources[self.resourceNames.R_CHARSPEECH].timeStamp > self.lastSpoke)
        {
            self.speak(self.requiredResources[self.resourceNames.R_CHARSPEECH].audioStream);
            
            self.lastSpoke = self.requiredResources[self.resourceNames.R_CHARSPEECH].timeStamp;
        }
        
        if( self.animationMixer )
        {
            self.animationMixer.update( delta );
            //helper.update();
        }
        
        if (!(self.providedResources[self.resourceNames.P_CHARMESH].pending))
        {
            self.emAnger(self.requiredResources[self.resourceNames.R_CHARFACIALEXPRESSION].data[Emotion.Anger]);
            self.emHappiness(self.requiredResources[self.resourceNames.R_CHARFACIALEXPRESSION].data[Emotion.Happiness]);
            self.emSadness(self.requiredResources[self.resourceNames.R_CHARFACIALEXPRESSION].data[Emotion.Sadness]);
            self.emSurprise(self.requiredResources[self.resourceNames.R_CHARFACIALEXPRESSION].data[Emotion.Surprise]);
        }
    }
});

var HapCharacterGirl = Class.create(HapCharacter,
{
    initialize: function($super)
    {
        var self = this;
        
        self.fileName = "char_girl";
        self.url = moduleDirectory+"/processors/HapCharacter/obj";
        
        $super();
        
        self.name = "HapCharacterGirl"; //unknown name, to be overriden by subclasses
    }
});

var HapCharacterGuy = Class.create(HapCharacter,
{
    initialize: function($super)
    {
        var self = this;
        
        self.fileName = "char_guy";
        self.url = moduleDirectory+"/processors/HapCharacter/obj";
        
        $super();
        
        self.name = "HapCharacterGuy"; //unknown name, to be overriden by subclasses
    }
});