/*
** Main logic
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

//------------------------------------------//
// Configuration
//------------------------------------------//

//current website url
location.origin = location.protocol + "//" + location.host;

//configuration file url
var mainConfig = location.origin+"/eEva/tests/MainframeTest/TestMainframeDiagram/appconfig.php";

var moduleDirectory = location.origin+"/eEva/app/modules";


//------------------------------------------//
// Main logic
//------------------------------------------//

//Mainframe instance
var mainframe = new Mainframe(mainConfig);
mainframe.run();
