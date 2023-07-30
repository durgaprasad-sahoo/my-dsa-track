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
    TreeNode* build(vector<int>& preorder, int&i, int upperbound){
        if(i==preorder.size()) return NULL;
        if(preorder[i]>upperbound) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, upperbound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder, i, INT_MAX);
    }
};
