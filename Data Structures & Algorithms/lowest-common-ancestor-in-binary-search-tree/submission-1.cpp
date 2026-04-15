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
    bool lca_bs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res)
    {

        if(!root)
            return false;

        if(res != NULL) return true; 

        bool root_p_or_q = (root == p || root == q);

        bool p_or_q_left = lca_bs(root->left, p , q, res);
        bool p_or_q_right = lca_bs(root->right, p , q, res);

        bool ans = ((p_or_q_left&&p_or_q_right) || (p_or_q_right&&root_p_or_q) || (root_p_or_q&&p_or_q_left));

        if(ans && (res == NULL))
        {
            res = root;
        }
        return (root_p_or_q||p_or_q_left||p_or_q_right); 

    }

    TreeNode* lca_bst(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res)
    {

        if(!root)
            return NULL;

        if(p->val > root->val && q->val > root->val)
            return lca_bst(root->right,p,q,res);
        else if(p->val < root->val && q->val < root->val)
            return lca_bst(root->left,p,q,res);
        else
            return root;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        return lca_bst(root,p,q,res);
        //return res;
        
    }
};
