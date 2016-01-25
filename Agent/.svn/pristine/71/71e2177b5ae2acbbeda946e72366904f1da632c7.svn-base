<?php

$xml = new SimpleXMLElement('<xml/>');

$module = $xml->addChild('module');
$module->addAttribute('name', "TextMultiChoice");
$module->addAttribute('uri', "http://".$_SERVER['SERVER_NAME']."/eEva/app/modules/sensors/TextMultiChoice");

Header('Content-type: text/xml');
print($xml->asXML());

?>
