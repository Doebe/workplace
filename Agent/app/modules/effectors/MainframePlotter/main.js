/*
** Test module
** Author: Mihai Polceanu
** E-mail: mpolcean@cs.fiu.edu
*/

/*****************************************************************\
** MainframePlotter module
\*****************************************************************/

var MainframePlotter = Class.create(Module,
{
    initialize: function($super)
    {
        var self = this;
        
        $super();
        
        self.name = "MainframePlotter"; //unknown name, to be overriden by subclasses
        self.type = ModuleType.Effector; //unknown type, to be overriden
        self.mandatory = false; //is this model mandatory ? to be overriden
        
    
        var $ = go.GraphObject.make;
        self.myDiagram = $(go.Diagram, "myDiagram",
        {
            initialContentAlignment: go.Spot.Left,
            "undoManager.isEnabled": false,
            // don't allow links within a group
            "linkingTool.linkValidation": differentGroups,
            "relinkingTool.linkValidation": differentGroups,
            /*
            mouseDrop: function(e,n)
            {
                // when the selection is dropped in the diagram's background,
                // and it includes any "port"s, cancel the drop
                if (n.containingGroup !== null && self.myDiagram.selection.all(selectionIncludesPorts))
                {
                    self.myDiagram.selection.each(function(p) { p.containingGroup = n.containingGroup; });
                } else {
                    self.myDiagram.currentTool.doCancel();
                }
            },
            */
            layout: $(go.LayeredDigraphLayout, { direction: 0, layerSpacing: 150 }),
        });

        function differentGroups(fromnode, fromport, tonode, toport)
        {
            return fromnode.containingGroup !== tonode.containingGroup;
        }

        function selectionIncludesPorts(n)
        {
            return n.containingGroup !== null && !myDiagram.selection.contains(n.containingGroup);
        }

        var UnselectedBrush = "lightgray";  // item appearance, if not "selected"
        var SelectedBrush = "dodgerblue";   // item appearance, if "selected"

        self.myDiagram.nodeTemplate = $(go.Node, "Auto",
            { selectionAdorned: false },
            { mouseDrop: function(e, n)
                {
                    /*
                    // when the selection is entirely ports and is dropped onto a Group, transfer membership
                    if (n.containingGroup !== null && myDiagram.selection.all(selectionIncludesPorts))
                    {
                        self.myDiagram.selection.each(function(p) { p.containingGroup = n.containingGroup; });
                    }
                    else
                    {
                        self.myDiagram.currentTool.doCancel();
                    }
                    */
                }
            },
            $(go.Shape,
            {
                name: "SHAPE",
                fill: UnselectedBrush, stroke: "gray",
                geometryString: "F1 m 0,0 l 5,0 1,4 -1,4 -5,0 1,-4 -1,-4 z",
                spot1: new go.Spot(0, 0, 5, 1),  // keep the text inside the shape
                spot2: new go.Spot(1, 1, -5, 0),
                // some port-related properties
                portId: "",
                toSpot: go.Spot.Left,
                toLinkable: false,
                fromSpot: go.Spot.Right,
                fromLinkable: false,
                cursor: "pointer"
            },
            new go.Binding("fill", "isSelected", function(s) { return s ? SelectedBrush : UnselectedBrush; }).ofObject(),
            new go.Binding("toLinkable", "_in"),
            new go.Binding("fromLinkable", "_in", function(b) { return !b; })),
            $(go.TextBlock, new go.Binding("text", "name"))
        );

        self.myDiagram.groupTemplate = $(go.Group,
            "Auto",
            { selectionAdorned: false, locationSpot: go.Spot.Center, locationObjectName: "ICON" },
            new go.Binding("location", "loc", go.Point.parse).makeTwoWay(go.Point.stringify),
            { mouseDrop: function(e, g)
                {
                    /*
                    // when the selection is entirely ports and is dropped onto a Group, transfer membership
                    if (self.myDiagram.selection.all(selectionIncludesPorts))
                    {
                        self.myDiagram.selection.each(function(p) { p.containingGroup = g; });
                    }
                    else
                    {
                        self.myDiagram.currentTool.doCancel();
                    }
                    */
                },
                layout: new InputOutputGroupLayout()
            },
            $(go.Shape, "RoundedRectangle",
            {
                stroke: "gray",
                strokeWidth: 2,
                fill: "white"
            },
            new go.Binding("stroke", "isSelected", function(b) { return b ? SelectedBrush : UnselectedBrush; }).ofObject()),
            $(go.Panel,
                "Vertical",
                { margin: 6 },
                $(go.TextBlock, new go.Binding("text", "name"), { alignment: go.Spot.Left }),
                $(go.Panel, "Spot",
                    { name: "ICON", height: 60 },  // an initial height; size will be set by InputOutputGroupLayout
                    $(go.Shape, { fill: null, stroke: null }),
                    $(go.Picture, moduleDirectory+"/effectors/MainframePlotter/images/gears.png", { width: 30, height: 30 })
                 )
            )
        );

        self.myDiagram.linkTemplate = $(go.Link,
            { routing: go.Link.Orthogonal, corner: 10, toShortLength: -3 },
            { relinkableFrom: false, relinkableTo: false },
            $(go.Shape, { stroke: "gray", strokeWidth: 2.5 })
        );

        //self.load();  // initialize myDiagram's model from the TextArea
        
        self.needsReload = true;
    },
    
    findPortNode: function (g, name, input)
    {
        var self = this;
        
        for (var it = g.memberParts; it.next(); )
        {
            var n = it.value;
            if (!(n instanceof go.Node)) continue;
            if (n.data.name === name && n.data._in === input) return n;
        }
        return null;
    },
    
    // Transform the given data to the data structures needed internally.
    // For each data object in the "ins" Array of the node data, add a "port" Node to the Group.
    // For each data object in the "outs" Array, add a "port" Node to the Group.
    // For each link data, convert the "from" and "fromPort" information to the actual "port" Node,
    // and then the same for "to" and "toPort".
    // The internal model uses property names starting with "_" to avoid having Model.toJson() write them out.
    setupDiagram: function (nodes, links)
    {
        var self = this;
        
        var model = new go.GraphLinksModel();
        model.linkFromKeyProperty = "_f";
        model.linkToKeyProperty = "_t";
        model.nodeIsGroupProperty = "_isg";
        model.nodeGroupKeyProperty = "_g";

        // first create all of the nodes, implemented as Groups
        for (var i = 0; i < nodes.length; i++)
        {
            var nodedata = nodes[i];
            nodedata._isg = true;
        }

        model.addNodeDataCollection(nodes);

        // now each node data will have a unique key, if not already specified
        // then create all of the ports, implemented as Nodes that are members of those Groups
        for (var i = 0; i < nodes.length; i++)
        {
            var nodedata = nodes[i];
            if (Array.isArray(nodedata.ins))
            {
                for (var j = 0; j < nodedata.ins.length; j++)
                {
                    var portdata = nodedata.ins[j];
                    portdata._in = true;
                    portdata._g = nodedata.key;
                }
                model.addNodeDataCollection(nodedata.ins);
                nodedata.ins = undefined;
            }
            if (Array.isArray(nodedata.outs))
            {
                for (var j = 0; j < nodedata.outs.length; j++)
                {
                    var portdata = nodedata.outs[j];
                    portdata._in = false;
                    portdata._g = nodedata.key;
                }
                model.addNodeDataCollection(nodedata.outs);
                nodedata.outs = undefined;
            }
        }

        self.myDiagram.model = model;

        // now Groups and Nodes exist, so can find the Node corresponding to a node's port
        // finally process all of the links, to account for ports actually being member nodes
        for (var i = 0; i < links.length; i++)
        {
            var linkdata = links[i];
            var fromNode = self.myDiagram.findNodeForKey(linkdata.from);
            var toNode = self.myDiagram.findNodeForKey(linkdata.to);
            if (fromNode !== null && toNode !== null)
            {
                // look in the Group for a "port" Node with the right name and directionality
                var fromPortNode = self.findPortNode(fromNode, linkdata.fromPort, false);
                var toPortNode = self.findPortNode(toNode, linkdata.toPort, true);
                if (fromPortNode !== null && toPortNode !== null)
                {
                    linkdata._f = fromPortNode.data.key;
                    linkdata._t = toPortNode.data.key;
                    linkdata.from = linkdata.fromPort = linkdata.to = linkdata.toPort = undefined;
                }
            }
        }
        model.addLinkDataCollection(links);
    },
    
    save: function ()
    {
        // can't just call myDiagram.model.toJson() -- need to transform to external format
        var m = new go.GraphLinksModel();
        m.linkFromPortIdProperty = "fromPort";
        m.linkToPortIdProperty = "toPort";
        var arr = self.myDiagram.model.nodeDataArray;

        self.myDiagram.nodes.each(function(g)
        {
            if (g instanceof go.Group)
            {
                g.data.ins = undefined;
                g.data.outs = undefined;
                m.addNodeData(g.data);
            }
        });

        self.myDiagram.nodes.each(function(n)
        {
            if (!(n instanceof go.Group))
            {
                var gd = n.containingGroup.data;
                var a = n.data._in ? gd.ins : gd.outs;
                if (!a)
                {
                    a = [];
                    if (n.data._in) gd.ins = a; else gd.outs = a;
                }
                a.push(n.data);
            }
        });

        self.myDiagram.links.each(function(l)
        {
            l.data.from = l.fromNode.containingGroup.data.key;
            l.data.fromPort = l.fromNode.data.name;
            l.data.to = l.toNode.containingGroup.data.key;
            l.data.toPort = l.toNode.data.name;
            m.addLinkData(l.data);
        });

        //document.getElementById("mySavedModel").value = m.toJson();
        self.myDiagram.isModified = false;
    },
    
    load: function ()
    {
        var self = this;
        //var m = go.Model.fromJson(document.getElementById("mySavedModel").value);
        
        var uniqueKey = 1;
        var jsonString = '{ "class": "go.GraphLinksModel", "linkFromPortIdProperty": "fromPort", "linkToPortIdProperty": "toPort", "nodeDataArray": [';
        var reqRes = {};
        var proRes = {};
        
    
        for (var i=0; i<mainframe.moduleExecutionOrder.length; ++i)
        {
            var moduleID = (uniqueKey++);
            jsonString += '{"key":'+moduleID+', "name":"'+mainframe.moduleExecutionOrder[i].name+'",';
            jsonString += '"ins":[ ';
            for (var j=0; j<mainframe.moduleExecutionOrder[i].requiredResources.length; ++j)
            {
                jsonString += '{"name":"'+mainframe.moduleExecutionOrder[i].requiredResources[j].name+'", "key":'+(uniqueKey++)+'}';
                
                if (reqRes[mainframe.moduleExecutionOrder[i].requiredResources[j].name] == null) reqRes[mainframe.moduleExecutionOrder[i].requiredResources[j].name] = [];
                reqRes[mainframe.moduleExecutionOrder[i].requiredResources[j].name].push(moduleID);
                
                if (j<mainframe.moduleExecutionOrder[i].requiredResources.length-1) jsonString += ',';
            }
            jsonString += ' ], "outs":[ ';
            
            for (var j=0; j<mainframe.moduleExecutionOrder[i].providedResources.length; ++j)
            {
                jsonString += '{"name":"'+mainframe.moduleExecutionOrder[i].providedResources[j].name+'", "key":'+(uniqueKey++)+'}';
                
                proRes[mainframe.moduleExecutionOrder[i].providedResources[j].name] = moduleID;
                
                if (j<mainframe.moduleExecutionOrder[i].providedResources.length-1) jsonString += ',';
            }

            jsonString += ']}';

            if (i<mainframe.moduleExecutionOrder.length-1) jsonString += ',';
        }
        
        jsonString += '], "linkDataArray": [ ';
        
        var firstComma = true;
        for(var proKey in proRes)
        {
            //console.log("proKey: "+proKey);
            if (!reqRes[proKey]) continue;
            for (var i=0; i<reqRes[proKey].length; ++i)
            {
                if (firstComma) firstComma = false;
                else jsonString += ',';
                jsonString += '{"from":'+proRes[proKey]+', "fromPort":"'+proKey+'", "to":'+reqRes[proKey][i]+', "toPort":"'+proKey+'"}';
            }
        }
        
        jsonString += '] }';
        
        var m = go.Model.fromJson(jsonString);
        self.setupDiagram(m.nodeDataArray, m.linkDataArray);
    },
    
    run: function()
    {
        var self = this;
        
        //do nothing
        
        if (self.active)
        {
            if (self.needsReload)
            {
                self.load();
                self.needsReload = false;
            }
        }
    }
});


// The Group.layout, for arranging the "port" Nodes within the Group
function InputOutputGroupLayout ()
{
    go.Layout.call(this);
}

go.Diagram.inherit(InputOutputGroupLayout, go.Layout);
InputOutputGroupLayout.prototype.doLayout = function(coll)
{
    if (coll === this.diagram)
    {
        coll = this.diagram.nodes;
    }
    else if (coll === this.group)
    {
        coll = this.group.memberParts;
    }
    
    var portSpacing = 2;
    var iconAreaWidth = 60;
    // compute the counts and areas of the inputs and the outputs
    var left = 0;
    var leftwidth = 0;  // max
    var leftheight = 0; // total
    var right = 0;
    var rightwidth = 0;  // max
    var rightheight = 0; // total
    
    coll.each(function(n)
    {
        if (n instanceof go.Link) return;  // ignore Links
        if (n.data._in)
        {
            left++;
            leftwidth = Math.max(leftwidth, n.actualBounds.width);
            leftheight += n.actualBounds.height;
        }
        else
        {
            right++;
            rightwidth = Math.max(rightwidth, n.actualBounds.width);
            rightheight += n.actualBounds.height;
        }
    });
    
    if (left > 0) leftheight += portSpacing * (left-1);
    if (right > 0) rightheight += portSpacing * (right-1);
    
    var loc = new go.Point(0, 0);
    if (this.group !== null && this.group.location.isReal()) loc = this.group.location;
    
    // first lay out the left side, the inputs
    var y = loc.y - leftheight/2;
    
    coll.each(function(n)
    {
        if (n instanceof go.Link) return;  // ignore Links
        if (!n.data._in) return;  // ignore outputs
        n.position = new go.Point(loc.x - iconAreaWidth/2 - leftwidth, y);
        y += n.actualBounds.height + portSpacing;
    });
    
    // now the right side, the outputs
    y = loc.y - rightheight/2;
    
    coll.each(function(n)
    {
        if (n instanceof go.Link) return;  // ignore Links
        if (n.data._in) return;  // ignore inputs
        n.position = new go.Point(loc.x + iconAreaWidth/2 + rightwidth - n.actualBounds.width, y);
        y += n.actualBounds.height + portSpacing;
    });
    
    // then position the group and size its icon area
    if (this.group !== null)
    {
        // position the group so that its ICON is in the middle, between the "ports"
        this.group.location = loc;
        // size the ICON so that it's wide enough to overlap the "ports" and tall enough to hold all of the "ports"
        var icon = this.group.findObject("ICON");
        if (icon !== null) icon.desiredSize = new go.Size(iconAreaWidth+leftwidth/2+rightwidth/2, Math.max(leftheight, rightheight) + 10);
    }
};