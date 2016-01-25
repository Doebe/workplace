<?php

$xml = new SimpleXMLElement('<xml/>');

$module = $xml->addChild('module');
$module->addAttribute('name', "DummyCharacterTextProvider");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/dummies/DummyCharacterTextProvider");

$module = $xml->addChild('module');
$module->addAttribute('name', "DummyEmotionStateProvider");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/dummies/DummyEmotionStateProvider");

$module = $xml->addChild('module');
$module->addAttribute('name', "WinSAPISynth");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/WinSAPISynth");

$module = $xml->addChild('module');
$module->addAttribute('name', "HapCharacterGirl");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/HapCharacter");

$module = $xml->addChild('module');
$module->addAttribute('name', "MainframePlotter");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/MainframePlotter");

Header('Content-type: text/xml');
print($xml->asXML());

?>
