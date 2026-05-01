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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        vector<int> res;

        while(cur || !st.empty())
        {
            // Do modified preorder (root → right → left) and reverse it.
            while(cur)
            {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            cur = cur->left;

        }

        reverse(res.begin(), res.end());

        return res;

        
    }
};