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

    int pathSum(TreeNode* root, int &maxSum)
    {
        if(!root)
            return 0;
        int left = max(pathSum(root->left, maxSum),0); //pick 0 if negative
        int right = max(pathSum(root->right, maxSum),0);
        int ans = root->val+ left + right;
        maxSum = max({ans, maxSum});
        return root->val + max({left, right});
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = -1001;
        pathSum(root, maxSum);
        return maxSum;
    }
};
