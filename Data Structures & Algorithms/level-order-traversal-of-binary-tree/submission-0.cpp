/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int level_size = q.size();
            vector<int> level_element;
            for(int i=0;i<level_size;i++)
            {
                TreeNode* e = q.front();
                if(e)
                {
                    //cout<<e->val<<" ";
                    level_element.push_back(e->val);
                }
                if(e->left)
                    q.push(e->left);
                if(e->right)
                    q.push(e->right);
                q.pop();
            }
            //cout<<endl;
            res.push_back(level_element);
        }
        return res;
    }
};
