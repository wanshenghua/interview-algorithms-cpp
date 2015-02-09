/*
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

Time Complexity:
Graph Traversal : O(|V| + |E|)
*/

 //Definition for undirected graph.
 struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
 };
 
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node){
			return NULL;
		}
		
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode*> old2new;
		UndirectedGraphNode *new_root = new UndirectedGraphNode(node->label);
		old2new[node] = new_root;
		
		queue<UndirectedGraphNode *> q;
		q.push(node);
		while(!q.empty()){
			UndirectedGraphNode *v = q.front();
			UndirectedGraphNode *new_v = old2new[v];
			q.pop();
			for(int i = 0; i < v->neighbors.size(); i++){
				UndirectedGraphNode *u = v->neighbors[i];
				if(old2new.find(u) == old2new.end()){//unvisited,clone node + copy the edge
					UndirectedGraphNode *new_u = new UndirectedGraphNode(u->label);
					old2new[u] = new_u;
					new_v->neighbors.push_back(new_u);
					q.push(u);
				}else{//visited, only copy the edge
					UndirectedGraphNode *new_u = old2new[u];
				    new_v->neighbors.push_back(new_u);					
				}
			}
		}
		return new_root;
    }
};