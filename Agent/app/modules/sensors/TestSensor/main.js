/*
** Test module
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** Module proof of concept
\*****************************************************************/

/*
** Test module - inheriting from Module class
*/
var TestSensor = Class.create(Module,
{
    initialize: function($super)
    {
        $super();
        
        this.name = "TestSensor"; //unknown name, to be overriden by subclasses
        this.type = ModuleType.Sensor; //unknown type, to be overriden
        this.mandatory = false; //is this model mandatory ? to be overriden
        
        this.providedResources.push(new UserText()); //dummy
    },
    
    run: function()
    {
        //do nothing
    }
});
