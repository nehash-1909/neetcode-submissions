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
    TreeNode* inorderTree(vector<int>& preorder, int &preIndex,vector<int>& inorder, int s, int e, unordered_map<int,int> hash)
    {
        int n = preorder.size();
        if(e >= n || s>e)
            return NULL;
        
        int preIndexVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(preIndexVal);
        int index = hash[preIndexVal];
        root->left = inorderTree(preorder, preIndex,inorder, s, index-1, hash);
        root->right = inorderTree(preorder, preIndex,inorder, index+1, e, hash);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {


        unordered_map<int,int> hash;
        int n = preorder.size();

        for(int i = 0; i < n; i++)
        {
            hash[inorder[i]] = i;
        }

        int preIndex = 0;
        return inorderTree(preorder,preIndex,inorder,0, n-1, hash);
        
    }
};
