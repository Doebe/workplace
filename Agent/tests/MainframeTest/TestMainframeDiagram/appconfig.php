<?php

$xml = new SimpleXMLElement('<xml/>');


$module = $xml->addChild('module');
$module->addAttribute('name', "TestSensor");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/sensors/TestSensor");

$module = $xml->addChild('module');
$module->addAttribute('name', "TestProcessor");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/TestProcessor");

$module = $xml->addChild('module');
$module->addAttribute('name', "TestEffector");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/TestEffector");


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
$module->addAttribute('name', "MainframePlotter");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/MainframePlotter");

Header('Content-type: text/xml');
print($xml->asXML());

?>
