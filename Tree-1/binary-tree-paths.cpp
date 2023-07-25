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
    vector<string>ans;
    void solve(TreeNode* root, string path){
        if(root==NULL) return;
        if(!root->left && !root->right){
            path += to_string(root->val);
            ans.emplace_back(path);
        }
        path+=to_string(root->val)+"->";
        if(root->left) solve(root->left, path);
        if(root->right) solve(root->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        solve(root, path);
        return ans;
    }
};
