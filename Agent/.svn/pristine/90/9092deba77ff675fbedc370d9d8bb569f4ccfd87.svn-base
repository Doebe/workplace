//====== Warns the user that their browser does not support WebGL ==========================================//
if(!Detector.webgl)
	Detector.addGetWebGLMessage();

//====== Global Variables ==================================================================================//
var camera, scene, render, stats;																			
var geometry, mesh, boy, girl, mesh2, mesh3, hapgl = null, floor, walls;	
var animations = {};
var clock = new THREE.Clock();																				
																											
var hap_width = window.innerWidth;																		
var hap_height = window.innerHeight;			

var light1;		

var wave = null;
var testAnim = null;



init();																										
animate();																									

function characterLoaded() {
	hapgl = HapGL.init({ 
		ttsUrl: 'http://cognac.cis.fiu.edu:88/',
		character: mesh,
		hair: mesh2
	});
	// to modify an action unit call: hapgl.setAU('AU1', <value>)

	setGUI();
}

//====== Three.JS Initial Setup ============================================================================//
function init() 																							
{																											
	//------ CAMERA ----------------------------------------------------------------------------------------//
	camera = new THREE.PerspectiveCamera																	
	(																										
		45, 																								
		hap_width / hap_height, 																	
		1, 																									
		15000																								
	);																										
																											
	camera.position.z = 400;																		
																											
	//------ SCENE -----------------------------------------------------------------------------------------//
	scene = new THREE.Scene();																				
																											
	//------ LIGHTS ----------------------------------------------------------------------------------------//

	var ambientLight = new THREE.AmbientLight(0xFFFFFF);
    scene.add(ambientLight);

	//------ CHARACTER -------------------------------------------------------------------------------------// 		
	var loader = new THREE.JSONLoader();																
																											
	loader.load("obj/twoAnimations.json", function(geometry, materials) 															
	{
		materials[0].skinning = true;
		//materials[1].skinning = true;
		
		materials[0].morphTargets = true;
		materials[0].map = THREE.ImageUtils.loadTexture('skins/skinfb.png');

		girl = new THREE.SkinnedMesh( geometry, new THREE.MeshFaceMaterial( materials ) );
		loadHair();
			scene.add( girl);
		
		girl.castShadow = true;
		girl.receiveShadow = true;
		mesh = girl;
		girl.visible = true;
		
		//loads the different animations into the animations array
		for(var i = 0; i < geometry.animations.length; ++i)
		{
			THREE.AnimationHandler.add( geometry.animations[ i ] );					
			var animName = geometry.animations[i].name;
			animations[animName] = new THREE.Animation(mesh, geometry.animations[i]);
		}
		
//					animation2 = new THREE.Animation( mesh, geometry.animations[1] );
		wave = animations['RightHandMove'];
		testAnim = animations['WaveAndHand'];
		});
//				/* uncomment when female character can animate two animations**************
	
		loader.load("obj/haptekMale.json", function(geometry, materials) 															
	{
		materials[0].skinning = false;
		//materials[1].skinning = true;
		
		materials[0].morphTargets = true;
		materials[0].map = THREE.ImageUtils.loadTexture('skins/body_maleMap.jpg');

		boy = new THREE.SkinnedMesh( geometry, new THREE.MeshFaceMaterial( materials ) );
//					loadHair();
			scene.add( boy );
		
		boy.castShadow = true;
		boy.receiveShadow = true;
		
		mesh = boy;
		boy.visible = false;

//					animation2 = new THREE.Animation( mesh, geometry.animations[1] );
//					animation2.play();
	}); 
	
//				  ***************uncomment when female character can animate two animations*/

    loader.load( "obj/office/Room.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Room.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
	loader.load( "obj/office/Carpet.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Carpet.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Seat1.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Seat1.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Seat2.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Seat2.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/TableFeet.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/TableFeet.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/TableTop.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/TableTop.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/PictureFrame.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/PictureFrame.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/ChairTop.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/ChairTop.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Bookcase1.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Bookcase1.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Bookcase2.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Bookcase2.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Bookcase3.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Bookcase2.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Column.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Column.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Crown.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Crown.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/ChairMiddle.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/ChairMiddle.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/ChairBottom.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/ChairBottom.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Diploma1.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Diploma1.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/Diploma2.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/Diploma2.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
    
    loader.load( "obj/office/ChairComfort.json", function( geometry, materials ) {
        materials[0].map = THREE.ImageUtils.loadTexture('obj/office/ChairComfort.png');
        materials[0].side = THREE.DoubleSide;
		var mesh = new THREE.Mesh( geometry, new THREE.MeshFaceMaterial( materials ) );
        mesh.position.z = -10;
		scene.add( mesh );
	} );
	
	var loadHair = function () {
		loader.load("obj/hair.js", function(geometry) 															
		{																										
			mesh2 = new THREE.Mesh(geometry, new THREE.MeshLambertMaterial( 									
			{ 																								
				map: THREE.ImageUtils.loadTexture('skins/hair1.png'),											
				alphaTest: 0.25																				
			}));

			characterLoaded();	
			//scene.add(mesh2);
			//mesh2.geometry.vertices[0].set(0, 100, 0);
		});
	};

	// loader.load("obj/hair.js", function(geometry) 															
	// {																										
	// 	mesh3 = new THREE.Mesh(geometry, new THREE.MeshLambertMaterial( 									
	// 	{ 																								
	// 		map: THREE.ImageUtils.loadTexture('skins/hair1.png'),											
	// 		alphaTest: 0.25																				
	// 	}));
	// });					
																											
	//------ RENDERER --------------------------------------------------------------------------------------//
	renderer = new THREE.WebGLRenderer({ alpha: true });
	renderer.setClearColor(0x000000, 0);																	
	renderer.setSize(hap_width, hap_height);		// before was: hap_width hap_height;	
	renderer.shadowMapEnabled = true;				
	jQuery(function($){$("div[id*=virtual-agent]").width(hap_width).height(hap_height).append(renderer.domElement);});
																											
	//------ CONTROLS --------------------------------------------------------------------------------------//
	controls = new THREE.OrbitControls(camera, renderer.domElement);										
																											
	//------ EXTRAS ----------------------------------------------------------------------------------------//
	window.addEventListener('resize', onWindowResize, false);												
																											
	stats = new Stats();																					
	stats.setMode(0); // 0: fps, 1: ms 																		
																											
	stats.domElement.style.position = 'absolute';															
	stats.domElement.style.left = '0px';																	
	stats.domElement.style.top = '0px';																		
																											
	document.body.appendChild( stats.domElement );															
	
	var imagePrefix = "images/webgl/dawnmountain-";
	var directions  = ["xpos", "xneg", "ypos", "yneg", "zpos", "zneg"];
	var imageSuffix = ".png";
	var skyGeometry = new THREE.BoxGeometry( 5000, 5000, 5000 );	

	var materialArray = [];
	for (var i = 0; i < 6; i++)
	{
		materialArray.push( new THREE.MeshBasicMaterial(
		{
			map: THREE.ImageUtils.loadTexture( imagePrefix + directions[i] + imageSuffix ),
			side: THREE.BackSide
		}));
	}
	
	var skyMaterial = new THREE.MeshFaceMaterial( materialArray );
	var skyBox = new THREE.Mesh( skyGeometry, skyMaterial );
	scene.add( skyBox );			
}																											
	
//====== Window Resize Event ===============================================================================//
function onWindowResize() 																					
{				
	hap_width = window.innerWidth;																		
	hap_height = window.innerHeight;																	
																											
	camera.aspect = hap_width / hap_height;															
	camera.updateProjectionMatrix();																		
																											
	renderer.setSize(hap_width, hap_height);														
}																											

//===== Blink Animation ====================================================================================//			
var blinkCT, blinkLT, blinkDelay;																							
var blink = blinkInit = false;																				
var blinkIsOpen = false;																					
																											
function blinkAction()																						
{																											
	if(blink)																								
	{																										
		if(blinkInit)																						
		{																									
			blinkDelay = Math.floor(Math.random() * (10 - 2 + 1) + 2);										
			blinkInit = false;																				
			blinkLT = Date.now();																			
		}																									
																											
		blinkCT = Date.now();																				
																											
		if(blinkIsOpen && (blinkCT - blinkLT > 50))															
		{																									
			mesh.morphTargetInfluences[1] = 0;																
			blinkIsOpen = false;																			
			blinkInit = true;																				
		}																									
																											
		else if(blinkCT - blinkLT > blinkDelay * 1000)														
		{																									
			mesh.morphTargetInfluences[1] = 1;																
			blinkIsOpen = true;																				
			blinkInit = true;																		
		}																									
	}																										
}																											

//===== Breathe Animation ==================================================================================//
var breatheLT, breatheCT;																					
var breathe = breatheInit = false;																			
var breatheDir = false;																						
var breatheDur = 1.75;																						
																											
function breatheAction()																					
{																											
	if(breathe)																								
	{																										
		if(breatheInit)																						
		{																									
			breatheInit = false;																			
			breatheDir = !breatheDir;																		
			breatheLT = Date.now();																			
		}																									
																											
		breatheCT = Date.now();																				
																											
		if(breatheDir)																						
		{																									
			if(breatheCT - breatheLT < breatheDur * 1000)													
				mesh.morphTargetInfluences[2] = (breatheCT - breatheLT)/(breatheDur * 1000);				
			else																							
				breatheInit = true;																			
		}																									
		else																								
		{																									
			if(breatheCT - breatheLT < breatheDur * 1000)													
				mesh.morphTargetInfluences[2] = 1 - (breatheCT - breatheLT)/(breatheDur * 1000);			
			else																							
				breatheInit = true;																			
		}																									
	}																										
}																											

//===== Dilate Action ======================================================================================//
var dilate = dilateInit = false;																				
var dilateDir = false;																						
var dilateLT, dilateCT, dilateDur;																			
var dilateMax = 0;																							
																											
var dWaitLT, dWaitCT, dWaitDur;																				
var dWait = dWaitInit = false;																				
																											
function dilateAction()																						
{																											
	if(dilate)																								
	{																										
		if(dWait)																							
		{																									
			if(dWaitInit)																					
			{																								
				dWaitDur = Math.random() * (5 - 0) + 0;														
				dWaitInit = false;																			
				dWaitLT = Date.now();																		
			}																								
																											
			dWaitCT = Date.now();																			
																											
			if(dWaitCT - dWaitLT > dWaitDur * 1000)															
				dWait = false;																				
		}																									
		else																							
		{																									
			if(dilateInit)																					
			{																								
				dilateDur = Math.random() * (5 - 3) + 3;													
				dilateDir = !dilateDir;																		
				dilateInit = dilateCycle = false;															
				dilateLT = Date.now();																		
			}																								
																											
			dilateCT = Date.now();																			
																											
			if(dilateDir)																					
			{																								
				if((dilateCT - dilateLT)/(dilateDur * 1000) < dilateMax)									
					mesh.morphTargetInfluences[3] = (dilateCT - dilateLT)/(dilateDur * 1000);				
				else																						
					dilateInit = true;																		
			}																								
			else																							
			{																								
				if((dilateCT - dilateLT)/(dilateDur * 1000) < dilateMax)									
					mesh.morphTargetInfluences[3] = dilateMax - (dilateCT - dilateLT)/(dilateDur * 1000);	
				else																						
				{																						
					dilateMax = Math.random() * (0.75 - 0.1) + 0.1;											
					dilateInit = true;																		
					dWait = true;																		
					dWaitInit = true;																		
				}																							
			}																								
		}																									
	}																										
}

//===== Main Loop Function =================================================================================//
function animate() 																							
{																											
	requestAnimationFrame(animate);																			
	render();																								
	stats.update();																							
}																											

var LT = Date.now();

//===== Main Render Function ===============================================================================//
function render()																							
{     		
	if (hapgl) {
        //'Sadness', 'Surprise', 'Anger', 'Disgust', 'Happiness'
        hapgl.setEmotion('Anger', videoJSEmotion.data[Emotion.Anger]);
        hapgl.setEmotion('Sadness', videoJSEmotion.data[Emotion.Sadness]);
        hapgl.setEmotion('Surprise', videoJSEmotion.data[Emotion.Surprise]);
        hapgl.setEmotion('Happiness', videoJSEmotion.data[Emotion.Happiness]);
        
		hapgl.render();
	}

	if(mesh)																								
	{																										
		blinkAction();																						
		breatheAction();																					
		dilateAction();	
	}		
		
	// if(mesh2)
	// {
	// 	var CT = Date.now();
		
	// 	for(var i = 0 ; i < mesh3.geometry.vertices.length ; i++)
	// 	{
	// 		var v = mesh3.geometry.vertices[i];
	// 		if(v.y < 0)
	// 		{
	// 			mesh2.geometry.dynamic = true;
	// 			v.add(new THREE.Vector3(0.1 * v.y/16 * Math.sin(Math.PI * CT/1000.0),0,0.05 * v.y/16 * Math.sin(Math.PI * CT/1000.0)));
	// 			//mesh2.geometry.vertices[i].set(v.x, v.y, v.z);
	// 			mesh2.geometry.verticesNeedUpdate = true;
	// 		}
	// 	}
	// }
																											
	renderer.render(scene, camera);	
	THREE.AnimationHandler.update( clock.getDelta() );
	
	controls.update( clock.getDelta() );
}																											
//==========================================================================================================//
