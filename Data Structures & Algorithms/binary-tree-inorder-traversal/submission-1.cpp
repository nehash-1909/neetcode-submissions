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
    void inorder(TreeNode* root, vector<int> &res)
    {
        if(root == NULL)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);

    } 
    vector<int> inorderTraversal(TreeNode* root) 
    {
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        stack<TreeNode*> st;
        vector<int> res;

        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                //prev = cur;
                cur = cur->left;
            }
            cur = st.top();
            res.push_back(cur->val);
            st.pop();
            cur = cur->right;

        }
        return res;

        #if 0
        vector<int> res;
        inorder(root, res);
        return res;
        #endif
        
    }
};