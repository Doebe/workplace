<?php

function getServerProtocol()
{
    if(!empty($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on')
    {
        $protocol = "https";
    }
    else
    {
        $protocol = "http";
    }
    return $protocol;
} 

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
$module->addAttribute('name', "DummyCharacterTextProvider");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/dummies/DummyCharacterTextProvider");
*/

$module = $xml->addChild('module');
$module->addAttribute('name', "ChromeSpeech");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/sensors/ChromeSpeech");

$module = $xml->addChild('module');
$module->addAttribute('name', "SpeechMirroringBehavior");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/SpeechMirroringBehavior");

$module = $xml->addChild('module');
$module->addAttribute('name', "WinSAPISynth");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/WinSAPISynth");

$module = $xml->addChild('module');
$module->addAttribute('name', "WebRTCVideo");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/sensors/WebRTCVideo");


$module = $xml->addChild('module');
$module->addAttribute('name', "VideoStreamDisplay");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/VideoStreamDisplay");


$module = $xml->addChild('module');
$module->addAttribute('name', "ClmTrackrWithOverlay");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/ClmTrackr");

$module = $xml->addChild('module');
$module->addAttribute('name', "FacialMirroringBehavior");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/FacialMirroringBehavior");

$module = $xml->addChild('module');
$module->addAttribute('name', "HapCharacterGirl");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/HapCharacter");


$module = $xml->addChild('module');
$module->addAttribute('name', "WebGLScene");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/WebGLScene");


$module = $xml->addChild('module');
$module->addAttribute('name', "MainframePlotter");
$module->addAttribute('uri', getServerProtocol()."://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/MainframePlotter");

Header('Content-type: text/xml');
print($xml->asXML());

?>
