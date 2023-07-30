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
    void find(TreeNode* root, int k, int& ans, int& count){
        if(!root) return;
        find(root->left, k, ans, count);
        count++;
        if(count==k){
            ans= root->val;
            return;
        }
        find(root->right, k, ans, count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int count =0;
        find(root, k, ans, count);
        return ans;
    }
};
