<?php

$xml = new SimpleXMLElement('<xml/>');

/*
$module = $xml->addChild('module');
$module->addAttribute('name', "TestSensor");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/sensors/TestSensor/TestSensor.js");

$module = $xml->addChild('module');
$module->addAttribute('name', "TestProcessor");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/TestProcessor/TestProcessor.js");

$module = $xml->addChild('module');
$module->addAttribute('name', "TestEffector");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/TestEffector/TestEffector.js");
*/

/*
$module = $xml->addChild('module');
$module->addAttribute('name', "ClmTrackr");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/sensors/ClmTrackr");
*/

/*
$module = $xml->addChild('module');
$module->addAttribute('name', "WebRTCVideo");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/sensors/WebRTCVideo");

$module = $xml->addChild('module');
$module->addAttribute('name', "VideoStreamDisplay");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/VideoStreamDisplay");

$module = $xml->addChild('module');
$module->addAttribute('name', "ClmTrackr");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/ClmTrackr");
*/

$module = $xml->addChild('module');
$module->addAttribute('name', "DummyEmotionStateProvider");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/dummies/DummyEmotionStateProvider");

$module = $xml->addChild('module');
$module->addAttribute('name', "DummyCharacterAudioStreamProvider");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/dummies/DummyCharacterAudioStreamProvider");

$module = $xml->addChild('module');
$module->addAttribute('name', "HapCharacterGirl");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/HapCharacter");

$module = $xml->addChild('module');
$module->addAttribute('name', "WebGLScene");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/WebGLScene");

Header('Content-type: text/xml');
print($xml->asXML());

?>
