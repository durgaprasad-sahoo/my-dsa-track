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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, unordered_map<int, int>&inmpp){
        if(preStart> preEnd || inStart> inEnd) return NULL;
        TreeNode* preRoot = new TreeNode(preorder[preStart]);
        int inRoot = inmpp[preRoot->val];
        int leftNodes = inRoot-inStart;

        preRoot->left  = build(preorder, preStart+1, preStart+leftNodes, inorder, inStart, inRoot-1, inmpp);
        preRoot->right = build(preorder, preStart+leftNodes+1, preEnd, inorder, inRoot+1, inEnd, inmpp);
        return preRoot;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>inmpp;
        for(int i=0; i< inorder.size();  i++){  //hashmap of inorder
            inmpp[inorder[i]]=i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmpp);
    }
};
