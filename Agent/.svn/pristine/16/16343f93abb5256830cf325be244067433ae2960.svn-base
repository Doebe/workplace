var gui, params, folder_actionUnits, folder_EmFACS_emotions, textController, installedVoices;
var hairtoggle = false, runningTest = false, test_word_nbr = -1, sentences_test_nbr = -1, paragraphs_test_nbr = -1,
	words_test = ['Adult', 'Aeroplane', 'Air', 'Aircraft Carrier', 'Airforce', 'Airport', 'Album', 'Alphabet', 'Apple', 'Arm', 'Army', 
				  'Baby', 'Backpack', 'Balloon', 'Banana', 'Bank', 'Barbecue', 'Bathroom', 'Bathtub', 'Bed', 'Bee', 'Beverage', 
				  'Bible', 'Bird', 'Bomb', 'Book', 'Boss', 'Bottle', 'Bowl', 'Box', 'Boy', 'Brain', 'Bridge', 'Butterfly', 
				  'Button', 'Cappuccino', 'Car', 'Car-race', 'Carpet', 'Carrot', 'Cave', 'Chair', 'Chess Board', 'Chief', 'Child', 
				  'Chisel', 'Chocolates', 'Church', 'Circle', 'Circus', 'Clock', 'Clown', 'Coffee', 'Coffee-shop', 
				  'Comet', 'Compact Disc', 'Compass', 'Computer', 'Crystal', 'Cup', 'Cycle', 'Data Base', 'Desk', 'Diamond', 'Dress', 
				  'Drill', 'Drink', 'Drum', 'Dung', 'Ears', 'Earth', 'Egg', 'Electricity', 'Elephant', 'Eraser', 'Explosive', 'Eyes', 
				  'Family', 'Fan', 'Feather', 'Festival', 'Film', 'Finger', 'Fire', 'Floodlight', 'Flower', 'Foot', 'Fork', 'Freeway', 
				  'Fruit', 'Fungus', 'Game', 'Garden', 'Gas', 'Gate', 'Gemstone', 'Girl', 'Gloves', 'God', 'Grapes', 'Guitar', 'Hammer', 
				  'Hat', 'Hieroglyph', 'Highway', 'Horoscope', 'Horse', 'Hose', 'Ice', 'Ice-cream', 'Insect', 'Jet fighter', 'Junk', 
				  'Kaleidoscope', 'Kitchen', 'Knife', 'Leather jacket', 'Leg', 'Library', 'Liquid', 'Magnet', 'Man', 'Map', 'Maze', 'Meat', 
				  'Meteor', 'Microscope', 'Milk', 'Milkshake', 'Mist', 'Money', 'Monster', 'Mosquito', 'Mouth', 'Nail', 'Navy', 
				  'Necklace', 'Needle', 'Onion', 'PaintBrush', 'Pants', 'Parachute', 'Passport', 'Pebble', 'Pendulum', 'Pepper', 'Perfume', 
				  'Pillow', 'Plane', 'Planet', 'Pocket', 'Post-office', 'Potato', 'Printer', 'Prison', 'Pyramid', 'Radar', 'Rainbow', 
				  'Record', 'Restaurant', 'Rifle', 'Ring', 'Robot', 'Rock', 'Rocket', 'Roof', 'Room', 'Rope', 'Saddle', 'Salt', 
				  'Sandpaper', 'Sandwich', 'Satellite', 'School', 'Sex', 'Ship', 'Shoes', 'Shop', 'Shower', 'Signature', 'Skeleton', 
				  'Slave', 'Snail', 'Software', 'Solid', 'Space Shuttle', 'Spectrum', 'Sphere', 'Spice', 'Spiral', 'Spoon', 'Sports-car', 
				  'Spot Light', 'Square', 'Staircase', 'Star', 'Stomach', 'Sun', 'Sunglasses', 'Surveyor', 'Swimming Pool', 'Sword', 'Table', 
				  'Tapestry', 'Teeth', 'Telescope', 'Television', 'Tennis racquet', 'Thermometer', 'Tiger', 'Toilet', 'Tongue', 'Torch', 
				  'Torpedo', 'Train', 'Treadmill', 'Triangle', 'Tunnel', 'Typewriter', 'Umbrella', 'Vacuum', 'Vampire', 'Videotape', 'Vulture', 
				  'Water', 'Weapon', 'Web', 'Wheelchair', 'Window', 'Woman', 'Worm', 'X-ray'],
	sentences_test= ['Learning something new can be a scary experience.', 
					 'One of the hardest things I\'ve ever had to do was learn how to swim.', 
					 'I was always afraid of the water, but I decided that swimming was an important skill that I should learn.', 
					 'I also thought it would be good exercise and help me to become physically stronger.', 
					 'What I didn\'t realize was that learning to swim would also make me a more confident person.',
				     'New situations always make me a bit nervous, and my first swimming lesson was no exception.', 
					 'After I changed into my bathing suit in the locker room, I stood timidly by the side of the pool waiting for the teacher and other students to show up.', 
					 'After a couple of minutes the teacher came over.', 
					 'She smiled and introduced herself, and two more students joined us.', 
					 'Although they were both older than me, they didn\'t seem to be embarrassed about not knowing how to swim.', 
					 'I began to feel more at ease.'],
	paragraphs_test = ['I have this fear. It causes my legs to shake. I break out in a cold sweat. I start jabbering to anyone who is nearby. As ' 
						+ 'thoughts of certain death run through my mind, the world appears a precious, treasured place. I imagine my own funeral, then'
						+ 'shrink back at the implications of where my thoughts are taking me. My stomach feels strange. My palms are clammy. I am '
						+ 'terrified of heights.Of course, it’s not really a fear of being in a high place. Rather, it is the view of a long way to fall, ' 
						+ 'of rocks far below me and no firm wall between me and the edge. My sense of security is screamingly absent. There are no guardrails, '
						+ 'flimsy though I picture them, or other safety devices. I can rely only on my own surefootedness—or lack thereof.'];


function setGUI()
{
	gui = new dat.GUI(); 

	params = 
	{
		AU1: 0, 
		AU2: 0, 
		AU4: 0, 
		AU5: 0,	
		AU6: 0,	
		AU7: 0,	
		AU8: 0,	
		AU9: 0,
		AU10: 0, 
		AU11: 0, 
		AU12: 0, 
		AU13: 0, 
		AU14: 0, 
		AU15: 0, 
		AU16: 0, 
		AU17: 0, 
		AU18: 0, 
		AU20: 0, 
		AU22: 0, 
		AU23: 0, 
		AU24: 0, 
		AU25: 0,
		AU26: 0, 
		AU27: 0, 
		AU28: 0, 
		AU38: 0, 
		AU39: 0, 
		AU41: 0, 
		AU42: 0,
		AU43: 0, 
		AU44: 0,
		Happiness: 0,
		Sadness: 0,
		Surprise: 0,
		Fear: 0,
		Anger: 0,
		Disgust: 0,
		
		text: "The quick, brown fox, jumps over the lazy dog.",
		ssml: "Hello, I'm Amy, a virtual health assistant. I am an expert in motivational interviewing, in which I assess people's lifestyle and provide them with feedback about it, and collaborate with them to make plans to change. I still don't have all my intelligence integrated yet, but I can show different facial expressions to build rapport with my clients, and when they seem to be at risk, <mark name='Sadness' /> I will show an empathic expression showing concern, however <mark name='Happiness' /> when they are doing well, I'm very supportive, and then sometimes people say surprising <mark name='Surprise' /> things!",

		blinktoggle: false,
		animationtoggle: true,
		breathetoggle: false,
		eyetoggle: false,
		hairtoggle: true,
//		male: false,			//OLD VERSIONS OF SWITCHING CHARACTERS
//		female: false,			//OLD VERSIONS OF SWITCHING CHARACTERS

		character: "Female",			//NEWVERSION OF SWITCH CHARACTERS
		
		voice: '',
		
		

		speak: function(speakEndCallback) {
			stopBreathe();
			return hapgl.speak(params.text, params.voice, speakEndCallback);
		},

		speakssml: function (speakEndCallback) {
			stopBreathe();
			var voice = _(installedVoices).findWhere({ name: params.voice });

			hapgl.lang = voice.culture;

			var res = (params.ssml).replace(/<bookmark mark=/g, "<mark name="); 

			hapgl.speakssml(res, params.voice, speakEndCallback);
		},

		speakWordsTest: function () {
			test_word_nbr++;
			if (test_word_nbr < words_test.length) {
				params.text = words_test[test_word_nbr];
				textController.updateDisplay();

				console.log("Word: " + params.text);
				params.speak(params.speakWordsTest);
			}
			else {
				test_word_nbr = -1
			}
		},

		speakSentencesTest: function () {
			sentences_test_nbr++;
			if (sentences_test_nbr < sentences_test.length) {
				params.text = sentences_test[sentences_test_nbr];

				console.log("Sentence: " + params.text);
				params.speak(params.speakSentencesTest);
			}
			else {
				sentences_test_nbr = -1
			}
		},
		
		speakParagraphsTest: function () {
			paragraphs_test_nbr++;
			if (paragraphs_test_nbr < paragraphs_test.length) {
				params.text = paragraphs_test[paragraphs_test_nbr];

				console.log("Paragraph: " + params.text);
				params.speak(params.speakParagraphsTest);
			}
			else {
				paragraphs_test_nbr = -1
			}
		},

		/*
		skin1: 	function()
		{ 
			mesh.material.map = THREE.ImageUtils.loadTexture('skins/skin1.png');
			mesh.material.needsUpdate = true;
		},
		
		skin2: function()
		{ 
			mesh.material.map = THREE.ImageUtils.loadTexture('skins/skin2.png');  
			mesh.material.needsUpdate = true;
		},
		*/
		
		reset: function()
		{  
			resetMorphs();							
		}
	};	
	
	//- FOLDER 1 : ACTION UNITS ---------------------------------------------------------------------------------------------------------------------------------//

	// var folder1 = gui.addFolder('Action Units');
	// var folder_AU_UpperFace= folder1.addFolder('Upper-Face AUs');
	// var folder_AU_LowerFace= folder1.addFolder('Lower-Face AUs');
	// var folder_AU_HeadEyePosition= folder1.addFolder('Head/Eye Position AUs');
	// var folder_EmFACS= folder1.addFolder('EmFACS');

	// var folder_actionUnits_items = Object.keys(folder_actionUnits);
	// for (var i = 0; i < folder_actionUnits_items.length; i++) {
	// 	var folder_item = folder_actionUnits_items[i];
	// 	var folder_item_desc = hapgl.AUName[folder_item];
	// 	if (_.contains(hapgl.upperfaceAUs, folder_item)) {
	// 		var item;
	// 		if (folder_actionUnits[folder_item] == 0) 
	// 			item = folder_AU_UpperFace.add(folder_actionUnits, folder_item).min(0).max(100).step(1).listen().onChange(_.partial(hapgl.setAU, folder_item));
	// 		else 
	// 			item = folder_AU_UpperFace.add(folder_actionUnits, folder_item);
	// 		$(item.domElement).parent().parent().find('span').attr('title', folder_item_desc)
	// 	} 
	// 	else if (_.contains(hapgl.lowerfaceAUs, folder_item)) {
	// 		var item = folder_AU_LowerFace.add(folder_actionUnits, folder_item).min(0).max(100).step(1).listen().onChange(_.partial(hapgl.setAU, folder_item));
	// 		$(item.domElement).parent().parent().find('span').attr('title', folder_item_desc)
	// 	} 
	// 	else if (_.contains(hapgl.headEyePositionAUs, folder_item)) {
	// 		var item = folder_AU_HeadEyePosition.add(folder_actionUnits, folder_item).min(0).max(100).step(1).listen().onChange(_.partial(hapgl.setAU, folder_item));
	// 		$(item.domElement).parent().parent().find('span').attr('title', folder_item_desc)
	// 	} 
	// 	else {
	// 		folder1.add(folder_actionUnits, folder_item).min(0).max(100).step(1).listen().onChange(_.partial(hapgl.setAU, folder_item));
	// 	}
	// }
	// var folder_EmFACS_items = Object.keys(folder_EmFACS_emotions);
	// for (var i = 0; i < folder_EmFACS_items.length; i++) {
	// 	var folder_item = folder_EmFACS_items[i];
	// 	folder_EmFACS.add(folder_EmFACS_emotions, folder_item).min(0).max(100).step(1).listen().onChange(_.partial(hapgl.setEmotion, folder_item));
	// }
	//- FOLDER 2 --------------------------------------------------------------------------------------------------------------------------------------------//

	var folder1 = gui.addFolder('Emotions');
    
	folder1.add(params, 'Happiness').min(0).max(100).step(1).listen().onChange(function(value){ 		hapgl.emHappiness(value/100);   		}); // mesh.morphTargetInfluences[ 48 ] = value/100;
	folder1.add(params, 'Sadness').min(0).max(100).step(1).listen().onChange(function(value){ 			hapgl.emSadness(value/100);   		}); //mesh.morphTargetInfluences[ 49 ] = value/100;
	folder1.add(params, 'Surprise').min(0).max(100).step(1).listen().onChange(function(value){ 			hapgl.emSurprise(value/100);    		}); //mesh.morphTargetInfluences[ 50 ] = value/100;
	folder1.add(params, 'Fear').min(0).max(100).step(1).listen().onChange(function(value){ 				hapgl.emFear(value/100);   		}); //mesh.morphTargetInfluences[ 51 ] = value/100;
	folder1.add(params, 'Disgust').min(0).max(100).step(1).listen().onChange(function(value){ 			hapgl.emDisgust(value/100);   		}); //mesh.morphTargetInfluences[ 52 ] = value/100;
	folder1.add(params, 'Anger').min(0).max(100).step(1).listen().onChange(function(value){ 			hapgl.emAnger(value/100);   		}); //mesh.morphTargetInfluences[ 53 ] = value/100;
    
	folder1.add(params, 'reset').name('Reset Morphs');

	var folder2 = gui.addFolder('Morphs');
	folder2.add(params, 'AU1').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 17 ] = value/100;   		});
	folder2.add(params, 'AU2').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 18 ] = value/100;   		});
	folder2.add(params, 'AU4').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 19 ] = value/100;   		});
	folder2.add(params, 'AU5').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 20 ] = value/100;   		});
	folder2.add(params, 'AU6').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 21 ] = value/100;   		});
	folder2.add(params, 'AU7').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 22 ] = value/100;   		});
	folder2.add(params, 'AU8').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 23 ] = value/100;   		});
	folder2.add(params, 'AU9').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 24 ] = value/100;   		});
	folder2.add(params, 'AU10').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 25 ] = value/100;   		});
	folder2.add(params, 'AU11').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 26 ] = value/100;   		});
	folder2.add(params, 'AU12').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 27 ] = value/100;   		});
	folder2.add(params, 'AU13').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 28 ] = value/100;   		});
	folder2.add(params, 'AU14').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 29 ] = value/100;   		});
	folder2.add(params, 'AU15').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 30 ] = value/100;   		});
	folder2.add(params, 'AU16').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 31 ] = value/100;   		});
	folder2.add(params, 'AU17').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 32 ] = value/100;   		});
	folder2.add(params, 'AU18').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 33 ] = value/100;   		});
	folder2.add(params, 'AU20').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 34 ] = value/100;   		});
	folder2.add(params, 'AU22').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 35 ] = value/100;   		});
	folder2.add(params, 'AU23').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 36 ] = value/100;   		});
	folder2.add(params, 'AU24').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 37 ] = value/100;   		});
	folder2.add(params, 'AU25').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 38 ] = value/100;   		});
	folder2.add(params, 'AU26').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 39 ] = value/100;   		});
	folder2.add(params, 'AU27').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 40 ] = value/100;   		});
	folder2.add(params, 'AU28').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 41 ] = value/100;   		});
	folder2.add(params, 'AU38').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 42 ] = value/100;   		});
	folder2.add(params, 'AU39').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 43 ] = value/100;   		});
	folder2.add(params, 'AU41').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 44 ] = value/100;   		});
	folder2.add(params, 'AU42').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 45 ] = value/100;   		});
	folder2.add(params, 'AU43').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 46 ] = value/100;   		});
	folder2.add(params, 'AU44').min(0).max(100).step(1).listen().onChange(function(value){ 				mesh.morphTargetInfluences[ 47 ] = value/100;   		});
	folder2.add(params, 'reset').name('Reset Morphs');
	
	//- FOLDER: SKINS ---------------------------------------------------------------------------------------------------------------------------------------//

	// var folderSkins = gui.addFolder('Skins');
	
	// folderSkins.add(params, 'skin1').name('Amy');
	// folderSkins.add(params, 'skin2').name('Lola');

	//- FOLDER: SPEAK ----------------------------------------------------------------------------------------------------------------------------------------//
	var folderSpeak = gui.addFolder('Speak');

	var voicesController = folderSpeak.add(params, 'voice', {}).name('Voice');

	hapgl.getVoices(function(voices) {
		installedVoices = voices;
        
        jQuery(function($){
		$.each(voices, function(i, voice) {
			voicesController.__select.add($("<option value='" + voice.name + "'>" + voice.name + ", " + voice.gender + " (" + voice.culture + ")</option>")[0]);
		});
        });

		if (voices && voices.length > 0) {	params.voice = voices[0].name;	}
	});

	textController = folderSpeak.add(params, 'text').name('Text-To-Speech');
	folderSpeak.add(params, 'speak').name('Speak Text!');
	folderSpeak.add(params, 'ssml').name('SSML-to-speak');
	folderSpeak.add(params, 'speakssml').name('Speak SSML!');
	folderSpeak.add(params, 'speakWordsTest').name('Speak Words Test!');
	folderSpeak.add(params, 'speakSentencesTest').name('Speak Sentences Test!');
	folderSpeak.add(params, 'speakParagraphsTest').name('Speak Paragraphs Test!');

	folderSpeak.open();
	
	//- FOLDER: EXTRAS -------------------------------------------------------------------------------------------------------------------------------------//		
	
	var folderExtras = gui.addFolder('Extras');

	folderExtras.add(params, 'blinktoggle').name('Blink').onChange(function(){						stopBlink();										});
	folderExtras.add(params, 'breathetoggle').name('Breathe').onChange(function(){					stopBreathe();										});
	folderExtras.add(params, 'eyetoggle').name('Dilate').onChange(function(){						stopDilate();										});
	folderExtras.add(params, 'animationtoggle').name('Animations').onChange(function(){						anim();										});
	//folderExtras.add(params, 'hairtoggle').name('Hair').onChange(function(value) {					hapgl.hair.visible = value;							});
//	folderExtras.add(params, 'male').name('Male').onChange(function(){							changeMale();											});
//	folderExtras.add(params, 'female').name('Female').onChange(function(){						changeFemale();											});
	
	folderExtras.add(params, 'character',["Female", "Male", "Female2", "Male2"]).name('Characters').onChange(function(e) {
	
		switch(e) {
			case "Female":
				boy.visible = false;
				mesh = girl;
				mesh.visible = true;
				break;
			case "Male":
				girl.visible = false;
				mesh=  boy;
				mesh.visible = true;
				break;
			case "Female2":
				break;
			case "Male2":
				break;
		}
		mesh.needsUpdate = true;
	});
	
	folderExtras.open();

	//--------------------------------------------------------------------------------------------------------------------------------------------------------//
	gui.open();
}

function resetMorphs()
{
	params.AU1 = 0, 
	params.AU2 = 0, 
	params.AU4 = 0, 
	params.AU5 = 0,	
	params.AU6 = 0,	
	params.AU7 = 0,	
	params.AU8 = 0,	
	params.AU9 = 0,
	params.AU10 = 0, 
	params.AU11 = 0, 
	params.AU12 = 0, 
	params.AU13 = 0, 
	params.AU14 = 0, 
	params.AU15 = 0, 
	params.AU16 = 0, 
	params.AU17 = 0, 
	params.AU18 = 0, 
	params.AU20 = 0, 
	params.AU22 = 0, 
	params.AU23 = 0, 
	params.AU24 = 0, 
	params.AU25 = 0,
	params.AU26 = 0, 
	params.AU27 = 0, 
	params.AU28 = 0, 
	params.AU38 = 0, 
	params.AU39 = 0, 
	params.AU41 = 0, 
	params.AU42 = 0,
	params.AU43 = 0, 
	params.AU44 = 0,
	params.Happiness = 0;
	params.Sadness = 0;
	params.Surprise = 0;
	params.Anger = 0;
	params.Disgust = 0;

	for(var i = 17 ; i < 48 ; i++) hapgl.setMorphTargetInfluence(i, 0); //mesh.morphTargetInfluences[i] = 0;
}

function stopBlink()
{  
	if(!params.blinktoggle)
	{
		mesh.morphTargetInfluences[1] = 0;
		blink = false;
	}
	else
	{
		blinkDir = false;
		blinkInit = true;
		blink = true;
	}							
}

function stopBreathe()
{
	if(!params.breathetoggle)
	{
		mesh.morphTargetInfluences[2] = 0;
		breathe = false;
	}
	else
	{
		breatheDir = false;
		breatheInit = true;
		breathe = true;
	}
}

function stopDilate()
{
	if(!params.eyetoggle)
	{
		mesh.morphTargetInfluences[3] = 0;
		dilate = false;
	}
	else
	{
		dilateInit = true;
		dilateDir = false;
		dilate = true;
	}
}
/* OLD character change
function changeMale()
{
	if(params.male)
	{
		mesh = boy;
		boy.visible = true;
	}
	else
	{
		boy.visible = false;
	}
}

function changeFemale()
{
	if(params.female)
	{
		mesh = girl;
		girl.visible = true;
	}
	else
	{
		girl.visible = false;
	}
}*/

function anim()
{
	if(params.animationtoggle)
	{
		wave.play(); // used to test wave animation
		//testAnim.play();
	}
	else
	{
		wave.play(); //used to test wave animation
		//testAnim.stop();
	}
}

function downloadURL(url) 
{
    var hiddenIFrameID = 'hiddenDownloader';
    var iframe = document.getElementById(hiddenIFrameID);
   
    if (iframe === null) 
    {
        iframe = document.createElement('iframe');
        iframe.id = hiddenIFrameID;
        iframe.style.display = 'none';
        document.body.appendChild(iframe);
    }
    
    iframe.src = url;
}

function phonemeToKey(phoneme)
{
	switch(phoneme)
	{
		case 'AA':
			return 1;
			break;
		case 'AA0':
			return 1;
			break;
		case 'AA1':
			return 1;
			break;
		case 'AA2':
			return 1;
			break;
		case 'AE':
			return 1;
			break;
		case 'AE0':
			return 1;
			break;
		case 'AE1':
			return 1;
			break;
		case 'AE2':
			return 1;
			break;
		case 'AH':
			return 1;
			break;
		case 'AH0':
			return 1; //was 1
			break;
		case 'AH1':
			return 1;
			break;
		case 'AH2':
			return 1;
			break;
		case 'AO':
			return 1;
			break;
		case 'AO0':
			return 1;
			break;
		case 'AO1':
			return 1;
			break;
		case 'AO2':
			return 1;
			break;
		case 'AW':
			return 1;
			break;
		case 'AW0':
			return 1;
			break;
		case 'AW1':
			return 1; //was 1
			break;
		case 'AW2':
			return 1;
			break;
		case 'AY':
			return 1;
			break;
		case 'AY0':
			return 1;
			break;
		case 'AY1':
			return 1;
			break;
		case 'AY2':
			return 1;
			break;
		case 'B':
			return 2;
			break;
		case 'CH':
			return 5;
			break;
		case 'D':
			return 8;
			break;
		case 'DH':
			return 8;
			break;
		case 'EH':
			return 10;
			break;
		case 'EH0':
			return 10;
			break;
		case 'EH1':
			return 10;
			break;
		case 'EH2':
			return 10;
			break;
		case 'ER':
			return 10;
			break;
		case 'ER0':
			return 10;
			break;
		case 'ER1':
			return 10;
			break;
		case 'ER2':
			return 10;
			break;
		case 'EY':
			return 10;
			break;
		case 'EY0':
			return 10;
			break;
		case 'EY1':
			return 10;
			break;
		case 'EY2':
			return 10;
			break;
		case 'F':
			return 15;
			break;
		case 'G':
			return 16;
			break;
		case 'HH':
			return -1;	 //was 17
			break;
		case 'IH':
			return 17;
			break;
		case 'IH0':
			return 17;
			break;
		case 'IH1':
			return 17;	//was 17
			break;
		case 'IH2':
			return 17;
			break;
		case 'IY':
			return 18;
			break;
		case 'IY0':
			return 18;
			break;
		case 'IY1':
			return 18;
			break;
		case 'IY2':
			return 18;
			break;
		case 'JH':
			return 32;	//was -1 
			break;
		case 'K':
			return -1;	// was -1
			break;
		case 'L':
			return 32;	// was 32
			break;
		case 'M':
			return 27;
			break;
		case 'N':
			return 32;
			break;
		case 'NG':
			return 32;
			break;
		case 'OW':
			return 37;
			break;
		case 'OW0':
			return 37;
			break;
		case 'OW1':
			return 37;
			break;
		case 'OW2':
			return 37;
			break;
		case 'OY':
			return 37;
			break;
		case 'OY0':
			return 37;
			break;
		case 'OY1':
			return 37;
			break;
		case 'OY2':
			return 37;
			break;
		case 'P':
			return 27;	//was -1
			break;
		case 'R':
			return 32;	//was -1
			break;
		case 'S':
			return 41;	//was 41
			break;
		case 'SH':
			return 41;
			break;
		case 'T':
			return 32;	//was -1
			break;
		case 'TH':
			return 50;	//was 50
			break;
		case 'UH':
			return 52;
			break;
		case 'UH0':
			return 52;
			break;
		case 'UH1':
			return 52;
			break;
		case 'UH2':
			return 52;
			break;
		case 'UW':
			return 54;
			break;
		case 'UW0':
			return 54;
			break;
		case 'UW1':
			return 54;
			break;
		case 'UW2':
			return 54;
			break;
		case 'V':
			return 37;	//was -1
			break;
		case 'W':
			return 37;	//was -1	
			break;
		case 'Y':
			return -1;	//was -1
			break;
		case 'Z':
			return 41;	//was -1
			break;
		case 'ZH':
			return 41;	//was -1
			break;
		case 'END':
			return 0;
			break;
		default:
			return -1;
			break;
	}

	return 0;
}
