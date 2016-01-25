/*
** WebGLScene module - adapted from original code by Guido Ruiz & ??
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** Useful declarations
\*****************************************************************/

var WebGLObject = Class.create
({
    initialize: function(name, url, scene)
    {
        var self = this;
        
        self.name = name;
        self.url = url;
        self.scene = scene;
        
        self.mesh = null;
        self.pending = true;
        
        self.visible = false;
        
        self.textureLoader = new THREE.TextureLoader();
        self.jsonLoader = new THREE.JSONLoader();
        
        self.load();
    },
    
    load: function()
    {
        var self = this;
        
        self.jsonLoader.load( self.url+"/"+self.name+".json", function( geometry, materials )
        {
            materials[0].map = self.textureLoader.load(self.url+"/"+self.name+".png");
            materials[0].side = THREE.DoubleSide;
            self.mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
            self.mesh.position.set(0, 0, 0);
            
            self.pending = false;
            self.setVisible(true);
        });
    },
    
    setVisible(visible)
    {
        var self = this;
        
        if (visible && !self.visible)
        {
            self.scene.add(self.mesh); //add object to scene
        }
        else if (!visible && self.visible)
        {
            self.scene.remove(self.mesh); //remove object from scene
        }
        
        //TODO: handle sceneObjects too....
        
        self.visible = visible;
    },
    
    step: function(delta)
    {
        
    }
});

/*****************************************************************\
** WebGLScene
\*****************************************************************/

var WebGLScene = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "WebGLScene"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Effector; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            R_CHARMESH: 0
        };
        
        self.requiredResources[self.resourceNames.R_CHARMESH] = new Mesh3D(); //dummy
        
        //var canvas = document.getElementById("webgl-app");
        
        self.hap_width = 100;
        self.hap_height = 100;
        
        
        jQuery(function($){
            self.hap_width  = $("#webgl-app").width();
            self.hap_height = $("#webgl-app").height();
        });
        
        //------------------------------------------------------------------------------------------------------//
        // WebGL detection & utils
        //------------------------------------------------------------------------------------------------------//
        
        if(!Detector.webgl)
        {
            Detector.addGetWebGLMessage();
        }
        
        self.clock = new THREE.Clock();
        self.textureLoader = new THREE.TextureLoader();
        
        //------------------------------------------------------------------------------------------------------//
        // Camera
        //------------------------------------------------------------------------------------------------------//
        
        self.camera = new THREE.PerspectiveCamera(45, self.hap_width / self.hap_height, 1, 15000);
        
        self.camera.position.z = 400;
        
        //------------------------------------------------------------------------------------------------------//
        // Scene
        //------------------------------------------------------------------------------------------------------//
        self.scene = new THREE.Scene();
        
        //------------------------------------------------------------------------------------------------------//
        // Lights
        //------------------------------------------------------------------------------------------------------//
        self.ambientLight = new THREE.AmbientLight(0xFFFFFF);
        self.scene.add(self.ambientLight);
        
        //------------------------------------------------------------------------------------------------------//
        // Renderer
        //------------------------------------------------------------------------------------------------------//
        self.renderer = new THREE.WebGLRenderer({ alpha: true });
        self.renderer.setClearColor(0x000000, 0);
        self.renderer.setSize(self.hap_width, self.hap_height);
        self.renderer.shadowMap.enabled = true;
        jQuery(function($){
            $("div[id*=webgl-app]").width("100%").height("100%").append(self.renderer.domElement);
        });
        self.onWindowResize(); //initialize view
        
        window.addEventListener('resize', self.onWindowResize.bind(this), false);
        
        //------------------------------------------------------------------------------------------------------//
        // Controls
        //------------------------------------------------------------------------------------------------------//
        self.controls = new THREE.OrbitControls(self.camera, self.renderer.domElement);
        
        //------------------------------------------------------------------------------------------------------//
        // Contents
        //------------------------------------------------------------------------------------------------------//
        self.sceneObjects = [];
        self.pendingSceneObjects = 0;
        
        //Skybox
        self.skybox = self.makeSkybox(moduleDirectory+"/effectors/WebGLScene/images/dawnmountain-");
        self.scene.add(self.skybox);
        
        //Object names
        var objects = [
            "Room",
            //"Seat1",
            //"Seat2",
            "TableFeet",
            "TableTop",
            "PictureFrame",
            "ChairTop",
            "Bookcase1",
            "Bookcase2",
            "Bookcase3",
            "Crown",
            //"ChairMiddle",
            "Diploma1",
            "Diploma2",
            "ChairComfort"
        ];
        
        //load objects
        for (var i=0; i<objects.length; ++i)
        {
            var obj = new WebGLObject(objects[i], moduleDirectory+"/effectors/WebGLScene/obj/office", self.scene);
            self.sceneObjects.push(obj);
        }
        
        //load character
        self.characterLoaded = false;
    },
    
    makeSkybox: function(imagePrefix)
    {
        var self = this;
        
        var directions  = ["xpos", "xneg", "ypos", "yneg", "zpos", "zneg"];
        var imageSuffix = ".png";
        var skyGeometry = new THREE.BoxGeometry( 5000, 5000, 5000 );
        
        
        var materialArray = [];
        for (var i = 0; i < 6; i++)
        {
            materialArray.push( new THREE.MeshBasicMaterial(
            {
                map: self.textureLoader.load(imagePrefix + directions[i] + imageSuffix ),
                side: THREE.BackSide
            }));
        }
        
        var skyMaterial = new THREE.MeshFaceMaterial( materialArray );
        var skyBox = new THREE.Mesh( skyGeometry, skyMaterial );
        
        return skyBox;
    },
    
    onWindowResize: function() 																					
    {
        var self = this;
        
        jQuery(function($){
            self.hap_width  = $("#webgl-app").width();
            self.hap_height = $("#webgl-app").outerHeight();
        });
        
        self.camera.aspect = self.hap_width / self.hap_height;
        self.camera.updateProjectionMatrix();
        
        self.renderer.setSize(self.hap_width, self.hap_height);
    },
    
    run: function()
    {
        var self = this;
        
        //should add char
        if (!self.characterLoaded)
        {
            if (self.requiredResources[self.resourceNames.R_CHARMESH].mesh && !self.requiredResources[self.resourceNames.R_CHARMESH].pending)
            {
                self.scene.add(self.requiredResources[self.resourceNames.R_CHARMESH].mesh);
                self.characterLoaded = true;
            }
        }
        
        self.renderer.render(self.scene, self.camera);
        
        /*
        var delta = self.clock.getDelta();
        for (var i=0; i<self.sceneObjects.length; ++i)
        {
            self.sceneObjects[i].step(delta);
        }
        */
    }
});