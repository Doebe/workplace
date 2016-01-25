/*
** Test module
** Author: Mihai Polceanu, Daniel Rivero
** E-mail: mpolcean@cs.fiu.edu, drive076@fiu.edu
*/
/*****************************************************************\
**Class for Questions and Answers
\*****************************************************************/

var QA = Class.create
({
    initialize: function(numChoices)
    {
        var self = this;
        
        self.questions = 
        {            
            ["Test Question 1", 1],
            ["Test Question 2", 2],
            ["Test Question 3", 3],
            ["Test Question 4", 4]            
        };
        
        self.divID = "multiChoice";
        self.numChoices = numChoices;
        
        self.input = document.createElement("INPUT");
        self.label = document.createElement("LABEL");
        
    },
    
    genHTML : function()
    {
        return " "
    }
});

/*****************************************************************\
** Module proof of concept
\*****************************************************************/

/*
** Test module - inheriting from Module class
*/
var TextMultiChoice = Class.create(Module,
{
    initialize: function($super)
    {
        
        var self = this;
        
        $super();
        
        self.name = "TextMultiChoice"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Sensor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            P_USERTEXT: 0
        };
        
        self.providedResources[self.resourceNames.P_USERTEXT] = /*add new Resource */;       

    },
 
    run: function()
    {
        //do nothing
        
    }
});
