/*
** Mainframe, Modules and Resources
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** Enumerations
\*****************************************************************/

/*
** Emotion enumeration
** Thou shalt use this throughout the application.
*/
var Emotion = {
    Anger: 0,
    Contempt: 1,
    Disgust: 2,
    Embarrassment: 3,
    Fear: 4,
    Happiness: 5,
    Pride: 6,
    Sadness: 7,
    Surprise: 8
};

var ModuleType = {
    Sensor: 0,
    Processor: 1,
    Effector: 2,
    Dummy: 3,
    Unknown: -1
};

/*
var Error = {
    REQUIRED_RESOURCE_NOT_PROVIDED: 0,
    
};
*/

/*****************************************************************\
** Useful definitions
\*****************************************************************/

jQuery(function($) // using jQuery's $
{
    jQuery.cachedScript = function( url, options )
    {
        // Allow user to set any option except for dataType, cache, and url
        options = $.extend( options || {}, {
            dataType: "script",
            //cache: true,
            cache: false, //debug
            url: url
        });

        // Use $.ajax() since it is more flexible than $.getScript
        // Return the jqXHR object so we can chain callbacks
        return jQuery.ajax( options );
    };
});

function loadScript(url, callback)
{
    var script = document.createElement("script")
    script.type = "text/javascript";

    if (script.readyState){  //IE
        script.onreadystatechange = function(){
            if (script.readyState == "loaded" ||
                    script.readyState == "complete"){
                script.onreadystatechange = null;
                callback();
            }
        };
    } else {  //Others
        script.onload = function(){
            callback();
        };
    }

    script.src = url;
    document.body.appendChild(script);
}

var ModuleDependency = Class.create
({
    initialize: function(scriptDir, scriptName, clientModule)
    {
        var self = this;
        
        self.dir = scriptDir;
        self.name = scriptName;
        self.module = clientModule;
        self.pending = false;
    },
    
    equals: function(dep)
    {
        var self = this;
        
        return (self.name==dep.name);
    }
});

/*****************************************************************\
** Mainframe
\*****************************************************************/

/*
** Mainframe class - configures and manages module creation and use
*/
var Mainframe = Class.create
({
    initialize: function(configURL)
    {
        var self = this; //cute trick to call prototype method from jquery block, because "this" is overriden
        
        self.config = configURL;
        
        self.configurationCompatible = true; //this is used to allow the mainframe to run, it is updated when adding/removing modules
        
        self.registeredModules = []; //all loaded modules
        self.registeredResources = [];
        self.requiredResources = [];
        
        self.moduleExecutionOrder = []; //this is a temporary sorted list of registered modules, used to run everything in a compatible way
        
        //javascript files cannot be unloaded from memory
        //so we might as well keep them loaded but disabled
        self.loadedModules = [];
        
        //module dependency management
        self.loadedModuleDependencies = [];
        
        //load main configuration
        jQuery(function($) // using jQuery's $
        {
            jQuery.get(configURL, function(d)
            {
                jQuery(d).find('module').each(function()
                {
                    var module = jQuery(this); //"this" is not the "self" ! it's scenarios like this that make using the self variable useful
                    var name = module.attr("name");
                    var uri = module.attr("uri");

                    self.registerModule(name, uri);
                });
            });
        });
    },
    
    registerModule: function(moduleName, uri)
    {
        var self = this; //cute trick to call prototype method from jquery block, because "this" is overriden
        
        //fast check, we'll need to check again later though, due to asynchronous module loading
        if (self.moduleRegistered(moduleName) > -1)
        {
            console.log( "Module "+moduleName+" already registered !" );
            return;
        }
        
        var index = self.moduleLoaded(moduleName);
        if (index == -1)
        {
            jQuery(function($){
                $.cachedScript( uri+"/dependencies.js" ).done(function( script, textStatus )
                {
                    self.registerModule_lazy.delay(0.1, self, moduleName, uri); //delayed module registration, in order to load dependencies first
                });
            });
        }
        else
        {
            var duplicateResource = self.verifyDuplicateResourceInModuleRegistration(this.loadedModules[index]);

            if (duplicateResource == null)
            {
                //register module
                self.registeredModules.push(self.loadedModules[index]);

                //register provided resources
                for (var i=0; i<newModule.providedResources.length; ++i)
                {
                    self.registeredResources.push(newModule.providedResources[i]);
                }
                
                console.log( "Load module "+moduleName+": registered from memory (previously loaded)" );
                
                //validate system
                self.verifyModuleCompatibility();
                
                newModule.setActive(true);
            }
            else
            {
                console.log("Module "+moduleName+" provides at least one duplicate resource: "+duplicateResource);
            }
        }
    },
    
    registerModule_lazy: function(self, moduleName, uri) //called by registerModule -- DO NOT CALL DIRECTLY !
    {
        //fast check, we'll need to check again later though, due to asynchronous module loading
        if (self.moduleRegistered(moduleName) > -1)
        {
            console.log( "Module "+moduleName+" already registered !" );
            return;
        }
        
        //check if all dependencies have been loaded (ideally we would check only for dependencies of this particular module, but it's not that big of a difference)
        var dependenciesLoaded = true;
        for (var i=0; i<self.loadedModuleDependencies.length; ++i)
        {
            if (self.loadedModuleDependencies[i].pending)
            {
                dependenciesLoaded = false;
            }
        }
        
        if (!dependenciesLoaded)
        {
            console.log("waiting for dependencies...");
            self.registerModule_lazy.delay(0.1, self, moduleName, uri); //delayed module registration, in order to load dependencies first
        }
        else
        {
            jQuery(function($){
                $.cachedScript( uri+"/main.js" ).done(function( script, textStatus )
                {
                    //check again, due to asynchronous module loading
                    if (self.moduleRegistered(moduleName) > -1)
                    {
                        console.log( "Module "+moduleName+" already registered !" );
                        return;
                    }
                    
                    var newModule = new window[moduleName];

                    var duplicateResource = self.verifyDuplicateResourceInModuleRegistration(newModule);

                    if (duplicateResource == null)
                    {
                        //register module
                        self.registeredModules.push(newModule);

                        //register provided resources
                        for (var i=0; i<newModule.providedResources.length; ++i)
                        {
                            self.registeredResources.push(newModule.providedResources[i]);
                        }

                        //validate system
                        self.verifyModuleCompatibility();
                        
                        newModule.setActive(true);
                        
                        console.log( "Load module "+moduleName+": "+textStatus );
                    }
                    else
                    {
                        console.log("Module "+moduleName+" provides at least one duplicate resource: "+duplicateResource);
                    }
                });
            });
        }
    },
    
    
    unregisterModule: function(moduleName)
    {
        var self = this;
        
        var index = self.moduleRegistered(moduleName);
        if (index == -1) return;
        
        self.registeredModules[index].setActive(false);
        
        for (var i=0; i<self.registeredModules[index].providedResources.length; ++i)
        {
            var res = providedResourceRegistered(self.registeredModules[index].providedResources[i]);
            self.registeredResources.splice(res, 1); //remove resource provided by this module
        }
        self.registeredModules.splice(index, 1); //remove element
    },
    
    verifyDuplicateResourceInModuleRegistration: function(newModule)
    {
        var self = this;
        
        //verify if this module provides resources already provided by another module
        var duplicateResource = null;
        for (var i=0; i<newModule.providedResources.length; ++i)
        {
            for (var j=0; j<self.registeredResources.length; ++j)
            {
                if (newModule.providedResources[i].name == self.registeredResources[j].name)
                {
                    //duplicate detected
                    duplicateResource = newModule.providedResources[i].name;
                }
            }
            if (duplicateResource != null) break;
        }
        
        return duplicateResource;
    },
    
    verifyModuleCompatibility: function()
    {
        var self = this;
        
        self.configurationCompatible = false; //stop mainframe run activity while checking compatibility
        
        var compatible = true;
        
        for (var i=0; i<self.registeredModules.length; ++i)
        {
            for (var j=0; j<self.registeredModules[i].requiredResources.length; ++j)
            {
                var found = false;
                for (var k=0; k<self.registeredResources.length; ++k)
                {
                    if (self.registeredModules[i].requiredResources[j].name == this.registeredResources[k].name)
                    {
                        //found required resource, let's link it
                        self.registeredModules[i].requiredResources[j] = this.registeredResources[k]; //use direct reference
                        found = true;
                    }
                }
                if (!found)
                {
                    compatible = false; //at least one resource could not be accounted for, therefore the configuration is not compatible
                    console.log("Could not find resource "+self.registeredModules[i].requiredResources[j].name+" required by module "+self.registeredModules[i].name+".");
                    break; //stop looking
                }
            }
            
            if (!compatible) break; //stop looking
        }
        
        if (compatible)
        {
            console.log("Module configuration OK !");
            self.updateModuleExecutionOrder();
        }
        else
        {
            console.log("Incompatible module configuration !");
        }
        self.configurationCompatible = compatible;
    },
    
    updateModuleExecutionOrder: function() //called by verifyModuleCompatibility, if everything is ok - DO NOT CALL DIRECTLY !
    {
        var self = this;
        
        //create sorted list of registered modules, based on compatible execution order (regarding resources provided/required)
        //WARNING ! this algorithm ASSUMES that the configuration is compatible !! do not call directly
        
        //we sweep in a Dijkstra-ish fashion, so that each module has all the necessary resources computed before it runs, and create a sorted list
        //the idea is to start from modules that don't need any resources, execute them, then run those which can be executed using the available resources, and so on...
        
        var remainingModules = self.registeredModules.slice(); //make a copy of entire list, to then keep track of which modules we haven't yet taken into account
        var availableResources = []; //keep track of which resources are provided so far
        
        self.moduleExecutionOrder = []; //clear old execution order
        
        var moduleInserted = true; //initial entry
        while (moduleInserted)
        {
            moduleInserted = false; //assume negative
            
            //sweep through unvisited modules to see if they fit in the configuration (all resources are provided for them)
            for (var i=0; i<remainingModules.length; ++i)
            {
                var gotAllRequiredResources = true; //starting with positive assumption, until found a missing resource (AND)
                for (var j=0; j<remainingModules[i].requiredResources.length; ++j)
                {
                    var gotRequiredResource = false; // starting with negative assumption, but change to true if found match (OR)
                    for (var k=0; k<availableResources.length; ++k)
                    {
                        if (remainingModules[i].requiredResources[j].name == availableResources[k].name)
                        {
                            gotRequiredResource = true;
                            break;
                        }
                    }
                    if (!gotRequiredResource)
                    {
                        gotAllRequiredResources = false;
                        break;
                    }
                }
                if (gotAllRequiredResources)
                {
                    //this module can be added to the configuration,
                    self.moduleExecutionOrder.push(remainingModules[i]);
                    
                    //add its provided resources to the list,
                    for (var j=0; j<remainingModules[i].providedResources.length; ++j)
                    {
                        availableResources.push(remainingModules[i].providedResources[j]);
                    }
                    
                    //and remove the module from the remaining list
                    remainingModules.splice(i,1);
                    i--; //go back one index, due to the removal
                    
                    moduleInserted = true; //flag change
                }
            }
        }
        
        //sanity check
        if (remainingModules.length > 0)
        {
            console.log("Terrible error in updateModuleExecutionOrder() - modules still remaining after sweep !");
        }
        else
        {
            console.log("Computed new module execution order !");
        }
    },
    
    moduleLoaded: function(moduleName)
    {
        var self = this;
        
        for (var i=0; i<self.loadedModules.length; ++i)
        {
            if (self.loadedModules[i].name == moduleName) return i;
        }
        return -1;
    },

    moduleRegistered: function(moduleName)
    {
        var self = this;
        
        for (var i=0; i<self.registeredModules.length; ++i)
        {
            if (self.registeredModules[i].name == moduleName) return i;
        }
        return -1;
    },
    
    providedResourceRegistered: function(resource)
    {
        var self = this;
        
        for (var i=0; i<self.registeredResources.length; ++i)
        {
            if (self.registeredResources[i] == resource) return i;
        }
        
        return -1;
    },
    
    addModuleDependency: function(dep)
    {
        var self = this;
        
        var alreadyLoaded = false;
        for (var i=0; i<self.loadedModuleDependencies.length; ++i)
        {
            if (self.loadedModuleDependencies[i].equals(dep))
            {
                alreadyLoaded = true;
                console.log("Dependency already loaded");
                break;
            }
        }
        
        if (alreadyLoaded)
        {
            console.log("Dependency "+scriptName+" of "+clientModule+" module already loaded ! If this is a name coincidence, please rename your dependency.");
            return;
        }
        
        dep.pending = true;
        self.loadedModuleDependencies.push(dep);
        
        loadScript(dep.dir+"/"+dep.name, function(){dep.pending = false;console.log("Dependency loaded by "+dep.module+" module: "+dep.name);});
    },
    
    
    run: function()
    {
        var self = this;
        
        requestAnimationFrame(self.run.bind(this));
        
        if (self.configurationCompatible)
        {
            console.log("Mainframe running...");
            
            //run all modules
            //as an optimization, this order has been precomputed and the modules are already sorted in a compatible configuration
            
            for (var i=0; i<self.moduleExecutionOrder.length; ++i)
            {
                self.moduleExecutionOrder[i].run();
            }
        }
    }
});

/*****************************************************************\
** Modules
\*****************************************************************/

/*
** Module class - treated as abstract class
*/
var Module = Class.create
({
    initialize: function()
    {
        var self = this;
        
        self.name = "unknown"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Unknown; //unknown type, to be overriden
        self.mandatory = false; //is this module mandatory ? to be overriden
        self.active = false;
        
        self.requiredResources = []; //to be filled by subclasses
        self.providedResources = []; //to be filled by subclasses
    },
    
    setActive: function(active)
    {
        var self = this;
        
        self.active = true;
    },
    
    run: function()
    {
        //to be overriden by subclasses
        console.log("WARNING: Default run method used !");
    }
});

/*****************************************************************\
** Resources
\*****************************************************************/

/*
** Resource class - treated as abstract class
*/
var Resource = Class.create
({
    initialize: function()
    {
        var self = this;
        
        self.name = "unknown"; //unknown name for resource, to be overriden by subclasses
    }
});

/*
** Basic emotional state
*/
var FacialExpression = Class.create(Resource,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "FacialExpression";
        self.data = {};
        self.data[Emotion.Anger] = 0.0;
        self.data[Emotion.Contempt] = 0.0;
        self.data[Emotion.Disgust] = 0.0;
        self.data[Emotion.Embarrassment] = 0.0;
        self.data[Emotion.Fear] = 0.0;
        self.data[Emotion.Happiness] = 0.0;
        self.data[Emotion.Pride] = 0.0;
        self.data[Emotion.Sadness] = 0.0;
        self.data[Emotion.Surprise] = 0.0;
    }
});

var UserFacialExpression = Class.create(FacialExpression,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "UserFacialExpression";
    }
});

var CharacterFacialExpression = Class.create(FacialExpression,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "CharacterFacialExpression";
    }
});

/*
** Basic text data - treated as abstract class
*/
var Text = Class.create(Resource,
{
    initialize: function()
    {
        var self = this;
        
        self.name = "Text";
        self.text = "";
        self.timestamp = 0;
    }
});

/*
** Concrete user text data
*/
var UserText = Class.create(Text,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "UserText";
    }
});

/*
** Part of Speech text data
*/
var PosText = Class.create(Resource,
{
    initialize: function($super)
    {
        var self =this;
        $super();
        
        self.name ="PosText";
        
        self.text = [];
        self.pos = [];
        
    }
});

/*
** Part of Speech sentiment text data
*/
var SentimentText = Class.create(Resource,
{
    initialize: function($super)
    {
        var self =this;
        $super();
        
        self.name ="Sentiment";
        
        self.sentiment = [];
        
    }
});

/*
** Concrete virtual character text data
*/
var CharacterText = Class.create(Text,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "CharacterText";
    }
});

/*
** Video stream
*/
var VideoStream = Class.create(Resource,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "VideoStream";
        self.videoStream = null;
    }
});

/*
** Three.js mesh
*/
var Mesh3D = Class.create(Resource,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "Mesh3D";
        self.mesh = null;
        self.pending = true; //Tagged as pending if the mesh hasn't been loaded yet, becomes false as soon as it is loaded
        self.visible = false;
        self.needsUpdate = false; //Whether the mesh has changed somehow...
    }
});

/*
** Contains audio files to be played, not truly a stream, but looks like one
*/
var CharacterAudioStream = Class.create(Resource,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "CharacterAudioStream";
        self.audioStream = null;
        self.visemes = null;
        self.bookmarks = null;
        self.timestamp = 0;
    }
});