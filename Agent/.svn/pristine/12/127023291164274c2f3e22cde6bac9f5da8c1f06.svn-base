<?php

$xml = new SimpleXMLElement('<xml/>');

$module = $xml->addChild('module');
$module->addAttribute('name', "DummyCharacterTextProvider");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/dummies/DummyCharacterTextProvider");

$module = $xml->addChild('module');
$module->addAttribute('name', "PartOfSpeech");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/PartOfSpeech");

$module = $xml->addChild('module');
$module->addAttribute('name', "Sentiment");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/processors/Sentiment");

$module = $xml->addChild('module');
$module->addAttribute('name', "MainframePlotter");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/effectors/MainframePlotter");

Header('Content-type: text/xml');
print($xml->asXML());

?>
