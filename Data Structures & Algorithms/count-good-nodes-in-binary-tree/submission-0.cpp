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
    void nodesGood(TreeNode* root, int maxVal, int &ans)
    {
        if(!root)
            return;
        if(root->val >= maxVal)
            ans++;
        nodesGood(root->left, max(root->val, maxVal), ans);
        nodesGood(root->right, max(root->val, maxVal), ans);
    }
    int goodNodes(TreeNode* root) 
    {
        int ans = 0;
        nodesGood(root, INT_MIN, ans);
        return ans;
    }
};
