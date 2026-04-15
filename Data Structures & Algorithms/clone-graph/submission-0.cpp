/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* dfs(Node* node) 
    {

        if(node == NULL)
            return node;
        
        if(map.contains(node))
            return map[node];
        
        

        Node* cloneNode = new Node(node->val);
        //vector<Node*>  cur_neighbors = ;

        map[node] = cloneNode;

        for(Node* n:node->neighbors)
        {
            cloneNode->neighbors.push_back(dfs(n));
        }

        return cloneNode;
        
        
    }
    Node* cloneGraph(Node* node) 
    {

        if(node == NULL)
            return node;

        return dfs(node); 
        
    }
};
