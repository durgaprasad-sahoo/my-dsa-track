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
    TreeNode* build(vector<int>&postorder, int postStart, int postEnd, vector<int>&inorder, int inStart, int inEnd, unordered_map<int, int>&inmap){
        if(postStart>postEnd || inStart > inEnd) return NULL;
        TreeNode* postRoot = new TreeNode(postorder[postEnd]);

        int inRoot = inmap[postRoot->val];
        int leftNodes = inRoot- inStart;
        postRoot->left = build(postorder, postStart, postStart+leftNodes-1, inorder, inStart, inRoot-1, inmap);
        postRoot->right = build(postorder, postStart+leftNodes, postEnd-1, inorder, inRoot+1, inEnd, inmap);
        return postRoot;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //making the hashmap of the inorder
        unordered_map<int, int>inmap;
        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]]=i;
        }
        return build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inmap);
    }
};
