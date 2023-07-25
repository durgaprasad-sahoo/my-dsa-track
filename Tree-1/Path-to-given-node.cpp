/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool findPath(TreeNode* root, int B, vector<int>&path){
    if(root==NULL) return false;
    path.push_back(root->val);
    if(root->val==B) return true;
    if(findPath(root->left, B, path) || findPath(root->right, B, path)) return true;
    else{
        path.pop_back();
        return false;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>path;
    if(A==NULL) return path;
    findPath(A, B, path);
    return path;
}
