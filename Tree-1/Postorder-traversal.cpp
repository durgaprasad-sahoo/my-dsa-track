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
    vector<int>ans;
    void postOrder(TreeNode* root){
        if(root==NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        ans.emplace_back(root->val);
    }
public:

    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};
