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
    int getMax(TreeNode* root, int &max_val)
    {
        if(!root)
            return 0;

        int left = getMax(root->left, max_val);
        int right = getMax(root->right, max_val);

        max_val = max( left + right, max_val);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(!root)
            return 0;

        int ans = -1;

        getMax(root, ans);
        return ans;
        
    }
};
