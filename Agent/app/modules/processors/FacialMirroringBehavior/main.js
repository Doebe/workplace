/*
** FacialMirroringBehavior module
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** FacialMirroringBehavior module
\*****************************************************************/

var FacialMirroringBehavior = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "FacialMirroringBehavior"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Processor; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
        self.resourceNames = {
            R_USERFACIALEXPRESSION: 0,
            
            P_CHARFACIALEXPRESSION: 0
        };
        
        self.requiredResources[self.resourceNames.R_USERFACIALEXPRESSION] = new UserFacialExpression(); //dummy
        
        self.providedResources[self.resourceNames.P_CHARFACIALEXPRESSION] = new CharacterFacialExpression();
    },
    
    run: function()
    {
        var self = this;
        
        for(var key in self.providedResources[self.resourceNames.P_CHARFACIALEXPRESSION].data)
        {
            self.providedResources[self.resourceNames.P_CHARFACIALEXPRESSION].data[key] = self.requiredResources[self.resourceNames.R_USERFACIALEXPRESSION].data[key];
            
            //console.log(key+": "+self.providedResources[self.resourceNames.P_CHAREMOTION].data[key]);
        }
    }
});
