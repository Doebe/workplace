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
var TestProcessor = Class.create(Module,
{
    initialize: function($super)
    {
        $super();
        
        this.name = "TestProcessor"; //unknown name, to be overriden by subclasses
        this.type = ModuleType.Processor; //unknown type, to be overriden
        this.mandatory = false; //is this model mandatory ? to be overriden
        
        this.requiredResources.push(new UserText()); //dummy
        
        this.providedResources.push(new FacialExpression()); //dummy
    },
    
    run: function()
    {
        //do nothing
    }
});
