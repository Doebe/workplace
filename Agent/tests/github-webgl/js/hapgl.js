/*
	Authors: Reynier Ortiz
	Description: Javascript version of HapFACS (created by Reza Amini)
*/
window.HapGL = (function() {
	function HapGLCharacter(options) {
		var self = this;

		self.ttsUrl = options.ttsUrl;
		self.serviceName = 'HapGLService.svc';
		
		var clock = new THREE.Clock(),
			blinkDelay = 0;

		self.mesh = options.character;
		self.hair = options.hair;
		self.lang = "en-US";

		self.upperfaceAUs = ['AU1', 'AU2', 'AU4', 'AU5', 'AU6', 'AU7', 'AU41', 'AU42', 'AU43', 'AU44', 'AU45'];
		self.lowerfaceAUs = ['AU8', 'AU9', 'AU10', 'AU11', 'AU12', 'AU13', 'AU14', 'AU15', 'AU16', 'AU17', 
							'AU18', 'AU20', 'AU22', 'AU23', 'AU24', 'AU25', 'AU26', 'AU27', 'AU28', 'AU38', 'AU39'];
		self.headEyePositionAUs = ['AU51', 'AU52'];

		self.AUName = {
			AU1: 'Inner Brow Raiser',
			AU2: 'Outer Brow Raiser',
			AU4: 'Brow Lowerer', 
			AU5: 'Upper Lid Raiser',
			AU6: 'Cheek Raiser',
			AU7: 'Lid Tightener',	
			AU8: 'Lips Toward Each Other',
			AU9: 'Nose Wrinkler',
			AU10: 'Upper Lip Raiser',
			AU11: 'Nasolabial Deepener',
			AU12: 'Lip Corner Puller',
			AU13: 'Sharp Lip Puller', 
			AU14: 'Dimpler',
			AU15: 'Lip Corner Depressor',
			AU16: 'Lower Lip Depressor', 
			AU17: 'Chin Raiser',
			AU18: 'Lip Pucker', 
			AU20: 'Lip stretcher', 
			AU22: 'Lip Funneler', 
			AU23: 'Lip Tightener',
			AU24: 'Lip Pressor', 
			AU25: 'Lips Part',
			AU26: 'Jaw Drop', 
			AU27: 'Mouth Stretch', 
			AU28: 'Lip Suck', 
			AU38: 'Nostril Dilator', 
			AU39: 'Nostril Compressor', 
			AU41: 'Glabella Lowerer', 
			AU42: 'Inner Eyebrow Lowerer',
			AU43: 'Eyes Closed', 
			AU44: 'Eyebrow Gatherer',
			AU45: 'Blink',
			AU46: 'Wink',
			AU51: 'Head Turn Left', 
			AU52: 'Head Turn Right'
		}

		// ---------------------------- FACS Action Units -----------------------------------
		var _AUstate = [];
		var _EmState = [];

		self.setAU = function(au, value) {
			if (au == null || au == undefined) throw '\'au\' can\'t be null or undefined';
			var morphTargets = self[au](value);

			if (morphTargets == null) return; // if it doesn't have morphTargets, then it's a gesture

			var morphTargetsPrev = [];
			if (_AUstate[au]) morphTargetsPrev = self[au](_AUstate[au]);
			_AUstate[au] = value;

			for (var i = 0; i < morphTargets.length; i++) {
				var morphTarget = morphTargets[i];
				var morphInfluenceIndex = self.mesh.morphTargetDictionary[morphTarget.name];
				var influenceDelta = morphTarget.value;				
				if (morphTargetsPrev[i]) influenceDelta -= morphTargetsPrev[i].value;
				var newInfluenceValue = self.mesh.morphTargetInfluences[morphInfluenceIndex] + influenceDelta;
 
				self.mesh.morphTargetInfluences[morphInfluenceIndex] = Math.abs(newInfluenceValue) > 0.0001 ? newInfluenceValue : 0;
			}
		};

		self.AU1 = function(intensity) { return [{ name: 'AU1', value: intensity / 100 }];	};

		self.AU2 = function(intensity) { 
			return [
				{ name: 'lBrowud', value: constants.LBrowUD_MAX_AU2 * intensity / 100 },
				{ name: 'rbrowud', value: constants.RBrowUD_MAX_AU2 * intensity / 100 }
			];
		};

		self.AU4 = function(intensity) { 
			return [
				{ name: 'eyes_sad', value: constants.eyes_sad_MAX_AU4 * intensity / 100 },
				{ name: 'midbrowud', value: constants.MidBrowUD_MAX_AU4 * intensity / 100 },
				{ name: 'rbrowud', value: constants.RBrowUD_MAX_AU4 * intensity / 100 },
				{ name: 'lBrowud', value: constants.LBrowUD_MAX_AU4 * intensity / 100 }	];
		};

		self.AU5 = function(intensity) { return [{ name: 'trust', value: constants.trust_MAX_AU5 * intensity / 100 }];	};

		self.AU6 = function(intensity) { 
			return [
				{ name: 'lipcornerl3ty', value: constants.lipcornerL3ty_MAX_AU6 * intensity / 100 },
				{ name: 'lipcornerr3ty', value: constants.lipcornerR3ty_MAX_AU6 * intensity / 100 },
				{ name: 'smile3', value: constants.smile3_MAX_AU6 * intensity / 100 },
				{ name: 'kiss', value: constants.kiss_MAX_AU6 * intensity / 100 }	];
		};

		self.AU7 = function(intensity) { return [{ name: 'distrust', value: constants.distrust_MAX_AU7 * intensity / 100 }]; };

		self.AU8 = function(intensity) { return [{ name: 'b', value: constants.b_MAX_AU8 * intensity / 100 }]; };

		self.AU9 = function(intensity) { 
			return [
				{ name: 'nostrilr3ty', value: constants.nostrilR3ty_MAX_AU9 * intensity / 100 },
				{ name: 'nostrilr3tx', value: constants.nostrilR3tx_MAX_AU9 * intensity / 100 },
				{ name: 'nostrill3ty', value: constants.nostrilL3ty_MAX_AU9 * intensity / 100 },
				{ name: 'nostrill3tx', value: constants.nostrilL3tx_MAX_AU9 * intensity / 100 },
				{ name: 'midbrowud', value: constants.MidBrowUD_MAX_AU9 * intensity / 100 }	];
		};

		self.AU10 = function(intensity) { 
			return [
				{ name: 'uh', value: constants.uh_MAX_AU10 * intensity / 100 },
				{ name: 'd', value: constants.d_MAX_AU10 * intensity / 100 },
				{ name: 'nostrill3ty', value: constants.nostrilL3ty_MAX_AU10 * intensity / 100 },
				{ name: 'nostrilr3ty', value: constants.nostrilR3ty_MAX_AU10 * intensity / 100 },
				{ name: 'nostrill3tx', value: constants.nostrilL3tx_MAX_AU10 * intensity / 100 },
				{ name: 'nostrilr3tx', value: constants.nostrilR3tx_MAX_AU10 * intensity / 100 },
				{ name: 'ow', value: constants.ow_MAX_AU10 * intensity / 100 },
				{ name: 'iy', value: constants.iy_MAX_AU10 * intensity / 100 } ];
		};

		self.AU11 = function(intensity) { 
			return [
				{ name: 'uh', value: constants.uh_MAX_AU11 * intensity / 100 },
				{ name: 'd', value: constants.d_MAX_AU11 * intensity / 100 },
				{ name: 'nostrill3tx', value: constants.nostrilL3tx_MAX_AU11 * intensity / 100 },
				{ name: 'nostrilr3tx', value: constants.nostrilR3tx_MAX_AU11 * intensity / 100 }
			];
		};

		self.AU12 = function(intensity) { return [{ name: 'smile3', value: constants.smile3_MAX_AU12 * intensity / 100 }];	};

		self.AU13 = function(intensity) { 
			return [
				{ name: 'lipcornerl3ty', value: constants.lipcornerL3ty_MAX_AU13 * intensity / 100 },
				{ name: 'lipcornerr3ty', value: constants.lipcornerR3ty_MAX_AU13 * intensity / 100 }
			];
		};

		self.AU14 = function(intensity) { 
			return [
				{ name: 'smirkL', value: constants.smirkL_MAX_AU14 * intensity / 100 },
				{ name: 'smirk', value: constants.smirk_MAX_AU14 * intensity / 100 }
			];
		};

		self.AU15 = function(intensity) { 
			return [
				{ name: 'lipcornerl3ty', value: constants.lipcornerL3ty_MAX_AU15 * intensity / 100 },
				{ name: 'lipcornerr3ty', value: constants.lipcornerR3ty_MAX_AU15 * intensity / 100 }
			];
		};

		self.AU16 = function(intensity) { return [{ name: 'th', value: constants.th_MAX_AU16 * intensity / 100 }]; };

		self.AU17 = function(intensity) { 
			return [
				{ name: 'lipcornerl3ty', value: constants.lipcornerL3ty_MAX_AU17 * intensity / 100 },
				{ name: 'lipcornerr3ty', value: constants.lipcornerR3ty_MAX_AU17 * intensity / 100 },
				{ name: 'aa', value: constants.aa_MAX_AU17 * intensity / 100 },
				{ name: 'ow', value: constants.ow_MAX_AU17 * intensity / 100 },
				{ name: 'mouth2ty', value: constants.mouth2ty_MAX_AU17 * intensity / 100 }
			];
		};

		self.AU18 = function(intensity) { return [{ name: 'kiss', value: constants.kiss_MAX_AU18 * intensity / 100 }]; };

		self.AU20 = function(intensity) { 
			return [
				{ name: 'b', value: constants.b_MAX_AU20 * intensity / 100 },
				{ name: 'lipcornerl3ty', value: constants.lipcornerL3ty_MAX_AU20 * intensity / 100 },
				{ name: 'lipcornerr3ty', value: constants.lipcornerR3ty_MAX_AU20 * intensity / 100 },
				{ name: 'mouth2ty', value: constants.mouth2ty_MAX_AU20 * intensity / 100 },
				{ name: 'nostrill3tx', value: constants.nostrilL3tx_MAX_AU20 * intensity / 100 },
				{ name: 'nostrilr3tx', value: constants.nostrilR3tx_MAX_AU20 * intensity / 100 },
				{ name: 'ow', value: constants.ow_MAX_AU20 * intensity / 100 },
				{ name: 'th', value: constants.th_MAX_AU20 * intensity / 100 }
			];
		};

		self.AU22 = function(intensity) { 
			return [
				{ name: 'ch', value: constants.ch_MAX_AU22 * intensity / 100 },
				{ name: 'uw', value: constants.uw_MAX_AU22 * intensity / 100 }
			];
		};

		self.AU23 = function(intensity) { return [{ name: 'b', value: constants.b_MAX_AU23 * intensity / 100 }]; };

		self.AU24 = function(intensity) { 
			return [
				{ name: 'kiss', value: constants.kiss_MAX_AU24 * intensity / 100 },
				{ name: 'b', value: constants.b_MAX_AU24 * intensity / 100 }
			];
		};

		self.AU25 = function(intensity) { 
			return [
				{ name: 'ch', value: constants.ch_MAX_AU25 * intensity / 100 },
				{ name: 'nostrill3ty', value: constants.nostrilL3ty_MAX_AU25 * intensity / 100 },
				{ name: 'nostrilr3ty', value: constants.nostrilR3ty_MAX_AU25 * intensity / 100 }
			];
		};

		self.AU26 = function(intensity) { return [{ name: 'aa', value: constants.aa_MAX_AU26 * intensity / 100 }]; };

		self.AU27 = function(intensity) { 
			return [
				{ name: 'aa', value: constants.aa_MAX_AU27 * intensity / 100 },
				{ name: 'ey', value: constants.ey_MAX_AU27 * intensity / 100 }
			];
		};

		self.AU28 = function(intensity) { 
			return [
				{ name: 'b', value: constants.b_MAX_AU28 * intensity / 100 },
				{ name: 'd', value: constants.d_MAX_AU28 * intensity / 100 },
				{ name: 'f', value: constants.f_MAX_AU28 * intensity / 100 }
			];
		};

		self.AU38 = function(intensity) { 
			return [
				{ name: 'nostrill3ty', value: constants.nostrilL3ty_MAX_AU38 * intensity / 100 },
				{ name: 'nostrill3tx', value: constants.nostrilL3tx_MAX_AU38 * intensity / 100 },
				{ name: 'nostrilr3ty', value: constants.nostrilR3ty_MAX_AU38 * intensity / 100 },
				{ name: 'nostrilr3tx', value: constants.nostrilR3tx_MAX_AU38 * intensity / 100 }
			];
		};

		self.AU39 = function(intensity) { 
			return [
				{ name: 'nostrill3ty', value: constants.nostrilL3ty_MAX_AU39 * intensity / 100 },
				{ name: 'nostrill3tx', value: constants.nostrilL3tx_MAX_AU39 * intensity / 100 },
				{ name: 'nostrilr3ty', value: constants.nostrilR3ty_MAX_AU39 * intensity / 100 },
				{ name: 'nostrilr3tx', value: constants.nostrilR3tx_MAX_AU39 * intensity / 100 }
			];
		};

		self.AU41 = function(intensity) { return [{ name: 'trust', value: constants.trust_MAX_AU41 * intensity / 100 }]; };

		self.AU42 = function(intensity) { return [{ name: 'midbrowud', value: constants.MidBrowUD_MAX_AU42 * intensity / 100 }]; };

		self.AU43 = function(intensity) { return [{ name: 'blink', value: constants.blink_MAX_AU43 * intensity / 100 }]; };

		self.AU44 = function(intensity) { 
			return [
				{ name: 'eyes_sad', value: constants.eyes_sad_MAX_AU44 * intensity / 100 },
				{ name: 'midbrowud', value: constants.MidBrowUD_MAX_AU44 * intensity / 100 },
				{ name: 'rbrowud', value: constants.RBrowUD_MAX_AU44 * intensity / 100 },
				{ name: 'lBrowud', value: constants.LBrowUD_MAX_AU44 * intensity / 100 }
			];
		};

		self.AU45 = function(state) {
			if (!state || state == 'closed') { 
				blinkDelay = Date.now();
				self.mesh.morphTargetInfluences[self.mesh.morphTargetDictionary['blink']] = 1;
			} else if (state == 'open')
				self.mesh.morphTargetInfluences[self.mesh.morphTargetDictionary['blink']] = 0;
		}

		self.AU51 = function(intensity) {
			var prevIntensity = _AUstate['AU51'] || 0;
			var angle = (Math.PI / 4) * ((intensity - prevIntensity) / 100);

			headTwist(angle);

			_AUstate['AU51'] = intensity;
		};

		self.AU52 = function(intensity) {
			var prevIntensity = _AUstate['AU52'] || 0;
			var angle = (-Math.PI / 4) * ((intensity - prevIntensity) / 100);

			headTwist(angle);

			_AUstate['AU52'] = intensity;
		};

		// TODO: This is just an initial attempt for head turns. It should not 
		//		 be considered as the final solution as it only rotates the head
		//       in the y axis, which means that will not be work if combined
		//		 with head nodding for example
		var headTwist = function(angle) {
			var axis = new THREE.Vector3( 0, 1, 0 );

			for(var i = 0 ; i < self.mesh.geometry.vertices.length; i++) {
				var v = self.mesh.geometry.vertices[i];
				if(v.y > -6)
				{
					self.mesh.geometry.dynamic = true;
					var rotationVector = new THREE.Vector3(v.x, v.y, v.z);
					
					rotationVector.applyAxisAngle( axis, angle );
					self.mesh.geometry.vertices[i].set(rotationVector.x, rotationVector.y, rotationVector.z);
				}

				// rotate all the morph targets
				for (var j = 0; j < self.mesh.geometry.morphTargets.length; j++) {
					var v = self.mesh.geometry.morphTargets[j].vertices[i];
					if(v.y > -6)
					{				
						var rotationVector = new THREE.Vector3(v.x, v.y, v.z);
						rotationVector.applyAxisAngle( axis, angle );
						self.mesh.geometry.morphTargets[j].vertices[i].set(rotationVector.x, rotationVector.y, rotationVector.z);
					}
				}
			}

			self.mesh.geometry.verticesNeedUpdate = true;
			self.mesh.geometry.morphTargetsNeedUpdate = true;

			// rotate hair
			if (self.hair) {
				for(var i = 0; i < self.hair.geometry.vertices.length; i++)  {
					self.hair.geometry.dynamic = true;
					var v = self.hair.geometry.vertices[i];
					var rotationVector = new THREE.Vector3(v.x, v.y, v.z);
	
					rotationVector.applyAxisAngle( axis, angle );
					self.hair.geometry.vertices[i].set(rotationVector.x, rotationVector.y, rotationVector.z);
				}

				self.hair.geometry.verticesNeedUpdate = true;
			}
		};


		// ------------------ EmFACS ----------------------------------------

		self.EmFACS = ['Sadness', 'Surprise', 'Anger', 'Disgust', 'Happiness'];

		self.setEmotion = function (emotion, intensity) {
		// 	var emPrevIntensity = 0;
		// 	if (_EmSate[emotion]) emPrevIntensity = _EmSate[emotion];
		// 	_EmSate[emotion] = intensity;

			self['em' + emotion](intensity);
		}

		self.emHappiness = function (intensity) {
			self.mesh.morphTargetInfluences[48] = intensity/100;
		}

		self.emSadness = function (intensity) {
			self.mesh.morphTargetInfluences[49] = intensity/100;
		}

		self.emSurprise = function (intensity) {
			self.mesh.morphTargetInfluences[50] = intensity/100;
		}

		self.emAnger = function (intensity) {
			self.mesh.morphTargetInfluences[53] = intensity/100;
		}

		self.emFear = function (intensity) {
			self.mesh.morphTargetInfluences[51] = intensity/100;
		}
		
		self.emDisgust = function (intensity) {
			self.mesh.morphTargetInfluences[52] = intensity/100;
		}

		var constants = {
			 AIntensity: 6.66, // 15% intensity
			 BIntensity: 3.33, // 30% intensity
			 CIntensity: 1.81, // 55% intensity
			 DIntensity: 1.17, // 85% intensity
			 MidBrowUD_MAX_AU1: -2.50,
			 LBrowUD_MAX_AU2: -1.50,
			 RBrowUD_MAX_AU2: -1.50,
			 MidBrowUD_MAX_AU4: 3.00,
			 LBrowUD_MAX_AU4: 0.60,
			 RBrowUD_MAX_AU4: 0.60,
			 eyes_sad_MAX_AU4: 1.25,
			 trust_MAX_AU5: -0.85,
			 lipcornerL3ty_MAX_AU6: -0.70,
			 lipcornerR3ty_MAX_AU6: -0.70,
			 smile3_MAX_AU6: 0.50,
			 kiss_MAX_AU6: 0.60,
			 distrust_MAX_AU7: 1.20,
			 b_MAX_AU8: 0.75,
			 nostrilL3ty_MAX_AU9: 0.60,
			 nostrilR3ty_MAX_AU9: 0.60,
			 nostrilL3tx_MAX_AU9: 0.10,
			 nostrilR3tx_MAX_AU9: -0.10,
			 MidBrowUD_MAX_AU9: 1.00,
			 uh_MAX_AU10: -1.70, // Previous value: -1.10,
			 ow_MAX_AU10: 0.61,
			 d_MAX_AU10: 2.76, // Previous value: 1.40,
			 iy_MAX_AU10: -0.50,
			 nostrilL3ty_MAX_AU10: 0.45,
			 nostrilR3ty_MAX_AU10: 0.45,
			 nostrilL3tx_MAX_AU10: 0.30,
			 nostrilR3tx_MAX_AU10: -0.30,
			 nostrilL3tx_MAX_AU11: 0.20,
			 nostrilR3tx_MAX_AU11: -0.20,
			 uh_MAX_AU11: -0.40,
			 d_MAX_AU11: 0.31,
			 smile3_MAX_AU12: 0.50,
			 lipcornerL3ty_MAX_AU13: 1.30,
			 lipcornerR3ty_MAX_AU13: 1.30,
			 smirk_MAX_AU14: 0.45,
			 smirkL_MAX_AU14: 0.60,
			 lipcornerL3ty_MAX_AU15: -1.30,
			 lipcornerR3ty_MAX_AU15: -1.30,
			 th_MAX_AU16: 0.60,
			 lipcornerL3ty_MAX_AU17: -0.60,
			 lipcornerR3ty_MAX_AU17: -0.60,
			 aa_MAX_AU17: -0.50,
			 ow_MAX_AU17: -0.40,
			 mouth2ty_MAX_AU17: 0.20,
			 kiss_MAX_AU18: 1.30,
			 lipcornerL3ty_MAX_AU20: -0.60,
			 lipcornerR3ty_MAX_AU20: -0.60,
			 b_MAX_AU20: 0.50,
			 ow_MAX_AU20: -1.30,
			 mouth2ty_MAX_AU20: -0.40,
			 nostrilL3tx_MAX_AU20: -0.50,
			 nostrilR3tx_MAX_AU20: 0.50,
			 th_MAX_AU20: -0.40,
			 ch_MAX_AU22: 1.00,
			 uw_MAX_AU22: 0.15,
			 b_MAX_AU23: 1.40,
			 b_MAX_AU24: 0.90,
			 kiss_MAX_AU24: 0.25,
			 ch_MAX_AU25: 0.80,
			 nostrilL3ty_MAX_AU25: 0.50,
			 nostrilR3ty_MAX_AU25: 0.50,
			 aa_MAX_AU26: 1.10,
			 aa_MAX_AU27: 1.30,
			 ey_MAX_AU27: 1.20,
			 b_MAX_AU28: 1.9,// Previous amount 1.30,
			 d_MAX_AU28: -0.7,
			 f_MAX_AU28: 0.28,
			 nostrilL3ty_MAX_AU38: 0.30,
			 nostrilR3ty_MAX_AU38: 0.30,
			 nostrilL3tx_MAX_AU38: 0.60,
			 nostrilR3tx_MAX_AU38: -0.60,
			 nostrilL3ty_MAX_AU39: -0.30,
			 nostrilR3ty_MAX_AU39: -0.30,
			 nostrilL3tx_MAX_AU39: -0.60,
			 nostrilR3tx_MAX_AU39: 0.60,
			 trust_MAX_AU41: 1.00,
			 MidBrowUD_MAX_AU42: 1.50,
			 blink_MAX_AU43: 1.40,
			 MidBrowUD_MAX_AU44: 1.00,
			 LBrowUD_MAX_AU44: -0.80,
			 RBrowUD_MAX_AU44: -0.90,
			 eyes_sad_MAX_AU44: 1.40,
			 HeadTwist_MAX_AU51: -0.62,
			 HeadTwist_MAX_AU52: 0.62,
			 HeadForward_MAX_AU53: -0.36,
			 HeadForward_MAX_AU54: 0.33,
			 HeadSideBend_MAX_AU55: 0.35,
			 HeadSideBend_MAX_AU56: -0.35,
			 HeadForward_MAX_AU57: -0.50,
			 NeckForward_MAX_AU57: 0.40,
			 HeadForward_MAX_AU58: 0.50,
			 NeckForward_MAX_AU58: -0.35,
			 LEyeBallLR_MAX_AU61: -0.45,
			 REyeBallLR_MAX_AU61: -0.45,
			 LEyeBallLR_MAX_AU62: 0.45,
			 REyeBallLR_MAX_AU62: 0.45,
			 LEyeBallUD_MAX_AU63: -0.18,
			 REyeBallUD_MAX_AU63: -0.18,
			 LEyeBallUD_MAX_AU64: 0.18,
			 REyeBallUD_MAX_AU64: 0.18,
			 LEyeBallLR_MAX_AU65: 0.38,
			 REyeBallLR_MAX_AU65: -0.38,
			 LEyeBallLR_MAX_AU66: -0.45,
			 REyeBallLR_MAX_AU66: 0.45
		}

		// ----------------- SPEAK -------------------------------------------------

		self.visemeIndex = -1;
		self.visemes = [];
		self.talkInitTime = null;
		self.isSpeaking = false;
		var _endSpeakCallback = null;

		var bookmarkIndex = -1;
		var bookmarks = [];
		var lastBookmark;

		var visemeMorphMapping = {
			'0': { name: 'neutral' },
			'1': { name: 'aa' },
			'2': { name: 'aa' },
			'3': { name: 'aa' },
			'4': { name: 'ey' },
			'5': { name: 'er' },
			'6': { name: 'ih' },
			'7': { name: 'uw' },
			'8': { name: 'ow' },
			'9': { name: 'aa' },
			'10': { name: 'ow' },
			'11': { name: 'aa' },
			'12': { name: 'ih' },
			'13': { name: 'n' },
			'14': { name: 'n' },
			'15': { name: 's' },
			'16': { name: 'ch' },
			'17': { name: 'th' },
			'18': { name: 'f' },
			'19': { name: 'd' },
			'20': { name: 'g' },
			'21': { name: 'm' }
		};

		self.getVoices = function(getVoicesCallback) {
			return $.ajax({
				type: 'GET',
				url: self.ttsUrl + "/" + self.serviceName + "/getVoices"
			}).done(function(response) { getVoicesCallback(JSON.parse(response).voices); } );
		};

		var Sound = (function () {
	   		var df = document.createDocumentFragment();
	   		var audioStarted;
		    return function Sound(src) {
		        var snd = new Audio(src);
		        df.appendChild(snd); // keep in fragment until finished playing
		        snd.addEventListener('ended', function () { 
		        	df.removeChild(snd); 
					// TODO: remove this, just for testing
		        	console.log('audio (ms): ' + (Date.now() - audioStarted));
		        });

		        snd.addEventListener('play', function () { 
		        	bookmarkIndex = 0;
		        	lastBookmark = bookmarks.length;
		        	console.log('Bookmark index is ' + lastBookmark + ' and the length of bookmarks is ' + lastBookmark);
					self.talkInitTime = Date.now();
					self.visemeIndex = 0;
					self.isSpeaking = true;
					audioStarted = Date.now();
		        });
				
		        snd.play();
		        return snd;
		    }
		}());

		var hapglservice_speak_callback = function(response) 
		{
			var speechInfo = JSON.parse(response);			
			self.visemes = speechInfo.visemes;
			bookmarks = speechInfo.bookmarks;
			console.log(self.bookmarks);

			Sound(speechInfo.audioFormat + "," + speechInfo.audioStream);
		};

		self.speak = function (text, voice, endSpeakCallback) {
			_endSpeakCallback = endSpeakCallback;
			return $.ajax({	
				type: 'GET',
				url: self.ttsUrl + "/" + self.serviceName + "/speak?text=" + encodeURI(text) + "&voice=" + encodeURI(voice)
			}).done(hapglservice_speak_callback);
		};

		self.speakssml = function (ssml, voice, endSpeakCallback) {
			_endSpeakCallback = endSpeakCallback;
			var ssml_formatted = '<?xml version="1.0"?>' 
							     + '<speak xmlns="http://www.w3.org/2001/10/synthesis" xmlns:dc="http://purl.org/dc/elements/1.1/" version="1.0" xml:lang="' + self.lang + '">' 
								 + '<p><s xml:lang="' + self.lang + '">' + ssml + '</s></p></speak>'

			return $.ajax({	
				type: 'GET',
				url: self.ttsUrl + "/" + self.serviceName + "/speakssml?ssml=" + encodeURI(ssml_formatted) + "&voice=" + encodeURI(voice)
			}).done(hapglservice_speak_callback);
		};

		var prevBookmark;
		var bookDur = 0.25;
		var sample;
		var bookStart = true;

		var renderBookmark = function()
		{
			if(bookmarkIndex >= 0)
			{
				if(bookmarkIndex == lastBookmark)
					bookmarkIndex = -1;
				else if(talkElapsed > bookmarks[bookmarkIndex].audioPosition)
				{
					if(bookmarkIndex == 0)
					{
						if(bookStart)
						{
							sample = Date.now();
							bookStart = false;
						}

						var bookDelta = Date.now() - sample;

						if(bookDelta < bookDur * 1000)
							self.setEmotion(bookmarks[bookmarkIndex].name, (bookDelta*100)/(bookDur*1000));
						else
						{
							self.setEmotion(bookmarks[bookmarkIndex].name, 100);
							prevBookmark = bookmarks[bookmarkIndex].name;
							bookmarkIndex++;
							bookStart = true;
						}
					}
					else if(bookmarkIndex < lastBookmark)
					{
						if(bookStart)
						{
							sample = Date.now();
							bookStart = false;
						}

						var bookDelta = Date.now() - sample;

						if(bookDelta < bookDur * 1000)
						{
							self.setEmotion(bookmarks[bookmarkIndex].name, (bookDelta*100)/(bookDur*1000));
							self.setEmotion(prevBookmark, 100 - ((bookDelta*100)/(bookDur*1000)));
						}
						else
						{
							self.setEmotion(prevBookmark, 0);
							self.setEmotion(bookmarks[bookmarkIndex].name, 100);
							prevBookmark = bookmarks[bookmarkIndex].name;
							bookmarkIndex++;
							bookStart = true;
						}
					}
				}
			}
		}

		var talkElapsed, visemeElapsed, viseme, nextViseme, increment;

		var renderViseme = function () {
			if (self.visemeIndex >= 0) { // then is speaking
				now = Date.now();
				talkElapsed = now - self.talkInitTime;
				viseme = self.visemes[self.visemeIndex];
				nextViseme = self.visemes[self.visemeIndex + 1];
				visemeElapsed = talkElapsed - viseme.audioPosition;

				if (talkElapsed < viseme.audioPosition) return;

				if (visemeElapsed < viseme.duration) {  // still in current viseme					
					increment = visemeElapsed / viseme.duration;

					if (!nextViseme || (viseme.number != nextViseme.number)) { // then need to transition visemes
						if (self.visemeIndex > 0) { // fade out current viseme
							var morphInfluenceIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[viseme.number + ''].name];
							self.mesh.morphTargetInfluences[morphInfluenceIndex] = 1 - increment;
						}

						if (nextViseme) { // fade in next viseme
							var nextVisemeMorphIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[nextViseme.number + ''].name];
							self.mesh.morphTargetInfluences[nextVisemeMorphIndex] = increment;
						}
					}
				}
				else { // it's time to render next viseme
					var morphInfluenceIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[viseme.number + ''].name];
					self.mesh.morphTargetInfluences[morphInfluenceIndex] = 0;

					if (nextViseme) {
						var nextVisemeMorphIndex = self.mesh.morphTargetDictionary[visemeMorphMapping[nextViseme.number + ''].name];
						self.mesh.morphTargetInfluences[nextVisemeMorphIndex] = 1;

						self.visemeIndex++;
					}
					else { // stop talking
						if(bookmarks.length > 0)
							self.setEmotion(bookmarks[bookmarks.length-1].name, 0);

						self.isSpeaking = false;
						self.visemeIndex = -1;
						self.talkInitTime = null;

						if (_endSpeakCallback && typeof _endSpeakCallback == 'function') _endSpeakCallback();
					}
				}
			}
		}

 		// ---------------- RENDER -----------------------------------------------

		self.render = function () {
			renderViseme();
			renderBookmark();

			if (blinkDelay > 0 && Date.now() - blinkDelay > 100) {
				blinkDelay = 0;
				self.AU45('open');
			}
		};
	}

	var HapGL = {
		init: function (mesh) {
			if (mesh != null) return new HapGLCharacter(mesh);
			return null;
		}
	};

	return HapGL;
}());