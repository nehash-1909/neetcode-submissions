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
    bool lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res)
    {

        if(!root)
            return false;

        if(res != NULL) return true; 

        bool root_p_or_q = (root == p || root == q);

        bool p_or_q_left = lca(root->left, p , q, res);
        bool p_or_q_right = lca(root->right, p , q, res);

        bool ans = ((p_or_q_left&&p_or_q_right) || (p_or_q_right&&root_p_or_q) || (root_p_or_q&&p_or_q_left));

        if(ans && (res == NULL))
        {
            res = root;
        }
        return (root_p_or_q||p_or_q_left||p_or_q_right); 

    }
//     bool lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res)
// {
//     if(!root)
//         return false;

//     bool root_p_or_q = (root == p || root == q);

//     bool left = lca(root->left, p , q, res);
//     bool right = lca(root->right, p , q, res);

//     bool ans = (left && right) ||
//                (root_p_or_q && left) ||
//                (root_p_or_q && right);

//     if(ans && res == NULL)
//         res = root;

//     return root_p_or_q || left || right;  // 🔥 IMPORTANT FIX
// }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        lca(root,p,q,res);
        return res;
        
    }
};
