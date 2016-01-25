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

Header('Content-type: text/xml');
print($xml->asXML());

?>
