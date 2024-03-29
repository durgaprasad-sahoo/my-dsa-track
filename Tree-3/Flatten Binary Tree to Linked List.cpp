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
private:
    void flat(TreeNode* node, TreeNode* &prev){
        if(!node) return;
        flat(node->right, prev);
        flat(node->left, prev);
        node->right= prev;
        node->left = NULL;
        prev = node;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        return flat(root, prev);
    }
};
