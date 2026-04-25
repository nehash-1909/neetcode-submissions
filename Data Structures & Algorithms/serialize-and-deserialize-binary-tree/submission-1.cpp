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

class Codec {
public:
    void serializeHelper(TreeNode* node, string &res) {
        if (!node) {
            res += "N,";
            return;
        }
        res += to_string(node->val) + ",";
        serializeHelper(node->left, res);
        serializeHelper(node->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }

    TreeNode* dfs_reverse(vector<string> &arr, int &idx)
    {
        if(idx >= (int)arr.size()) return NULL;

        if(arr[idx] == "N")
        {
            idx++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(arr[idx]));
        idx++;

        node->left = dfs_reverse(arr, idx);
        node->right = dfs_reverse(arr, idx);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> arr;
        int i = 0;

        while(i < (int)data.size())
        {
            string s = "";
            while((i < (int)data.size()) && (data[i] != ','))
            {
                s += data[i];
                i++;
            }
            if (!s.empty()) arr.push_back(s);
            i++; // skip ','
        }

        int idx = 0;
        return dfs_reverse(arr, idx);
    }
};