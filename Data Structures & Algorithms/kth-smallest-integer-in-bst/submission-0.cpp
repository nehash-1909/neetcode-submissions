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
    void getVal(TreeNode* root, int &k, int &ans)
    {
        if(!root)
            return;
        getVal(root->left, k, ans);
        --k;
        //cout<<root->val<<" "<<k<<endl;
        if(k==0 && ans == INT_MIN)
        {
            //cout<<"ans found"<<endl;
            ans = root->val;
        }
        
        getVal(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {

        int ans = INT_MIN;
        getVal(root,k, ans);
        return ans;
        
    }
};
