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
    bool sameTree(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
            return true;
        if((!p && q) || (p && !q))
            return false;
        if(p->val != q->val)
            return false;
        
        bool left = sameTree(p->left, q->left);
        bool right = sameTree(p->right, q->right);

        return (left&&right&&(p->val == q->val));

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();

            if(sameTree(node, subRoot))
            {
                return true;
            }
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
            q.pop();
        }
        return false;
        
    }
};
