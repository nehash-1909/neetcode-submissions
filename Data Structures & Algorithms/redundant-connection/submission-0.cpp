class Solution {
public:
    int find(vector<int> &parent, int node)
    {
        if(node == parent[node])
            return node;
        
        return find(parent,parent[node]);
    }
    bool unionSet(vector<int> &parent, vector<int> &sizeNode,int node1, int node2)
    {
        int node1_p = find(parent,node1);
        int node2_p = find(parent,node2);

        if(node1_p == node2_p)// same parents
            return false; // cycle
        if(sizeNode[node1_p] > sizeNode[node2_p])
        {
            parent[node2_p] = node1_p;
            sizeNode[node1_p] += sizeNode[node2_p];
        }
        else
        {
            parent[node1_p] = node2_p;
            sizeNode[node2_p] += sizeNode[node1_p];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {

        int n = edges.size();

        vector<int> parent(n+1,1);
        vector<int> sizeNode(n+1,1);

        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }

        for(int i=0;i<n;i++)
        {
            if(unionSet(parent, sizeNode, edges[i][0], edges[i][1]) == false)
                return {edges[i][0], edges[i][1]};
        }

        return {};



    }
};
