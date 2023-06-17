#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int data)
    	{
        	data = data;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int data, vector<graphNode *> neighbours)
    	{
        	data = data;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void dfs(graphNode*node,graphNode*copy,vector<graphNode*>&vis){
	vis[copy->data]=copy;
	for(auto x:node->neighbours){
		if(vis[x->data]==NULL){
			graphNode*newnode=new graphNode(x->data);
			(copy->neighbours).push_back(newnode);
			dfs(x,newnode,vis);
		}else{
			(copy->neighbours).push_back(vis[x->data]);
		}
	}
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(node==NULL) return NULL;
	graphNode*copy=new graphNode(node->data);
	vector<graphNode*>vis(100001,NULL);
	dfs(node,copy,vis);
	return copy;
}