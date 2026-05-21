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
    pair<int,int> dfs(TreeNode* root) 
    {
        if(root == NULL)
            return {0,0};
        auto leftPair = dfs(root->left);
        auto rightPair = dfs(root->right);
         // root + children without root value
        int withroot = root->val+ leftPair.second + rightPair.second;

        int withoutroot = max(leftPair.second, leftPair.first) + max(rightPair.second, rightPair.first);

        return {withroot,withoutroot};
    }
    int rob(TreeNode* root) 
    {
        auto val = dfs(root);
        return max(val.first, val.second);
    }
};