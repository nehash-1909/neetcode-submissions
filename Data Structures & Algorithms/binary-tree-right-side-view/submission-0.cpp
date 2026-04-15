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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int q_len = q.size();

            for(int i=0;i<q_len;i++)
            {
                TreeNode* next_element = q.front();
                if(next_element->left)
                    q.push(next_element->left);
                if(next_element->right)
                    q.push(next_element->right);
                if(i == q_len-1)
                    res.push_back(next_element->val);
                q.pop();
            }
        }

        return res;


    }
};
