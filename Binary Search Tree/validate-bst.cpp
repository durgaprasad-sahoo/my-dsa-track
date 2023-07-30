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
    bool check(TreeNode* node, long leftMaxRange, long rightMaxRange){
        if(!node) return true;
        if(node->val <= leftMaxRange  or node->val >= rightMaxRange) return false;
        if(!check(node->left, leftMaxRange, node->val)) return false;
        if(!check(node->right, node->val, rightMaxRange)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};
