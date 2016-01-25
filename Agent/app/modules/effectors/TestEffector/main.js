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
var TestEffector = Class.create(Module,
{
    initialize: function($super)
    {
        $super();
        
        this.name = "TestEffector"; //unknown name, to be overriden by subclasses
        this.type = ModuleType.Effector; //unknown type, to be overriden
        this.mandatory = false; //is this model mandatory ? to be overriden
        
        this.requiredResources.push(new FacialExpression()); //dummy
    },
    
    run: function()
    {
        //do nothing
    }
});
