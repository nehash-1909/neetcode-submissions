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
        int left = pathSum(root->left, maxSum);
        int right = pathSum(root->right, maxSum);
        int ans = root->val+ left + right;
        maxSum = max({left+root->val, right+root->val, root->val,ans, maxSum});
        cout<<left<<" "<<right<<" "<<root->val<<" "<<maxSum<<" "<<ans<<endl;
        return max({left+root->val, right+root->val, root->val});
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = -1001;
        pathSum(root, maxSum);
        return maxSum;
    }
};
