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
    TreeNode* toBeDeleted(TreeNode* node){
        if(!node->left) return node->right;
        else if(!node->right) return node->left;
        else{ //if both the nodes are present
            TreeNode* nodesRightChild = node->right;  //this needs to be joined at left's extreme right's end
            TreeNode* leftsLastRightNode = findExtremeRight(node->left);
            leftsLastRightNode->right = nodesRightChild;
            return node->left;
        }
    }
    TreeNode* findExtremeRight(TreeNode* node){
        if(!node->right) return node; //return the last right node
        else return findExtremeRight(node->right); //move towards right
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key) return toBeDeleted(root);
        TreeNode* tempRoot = root;
        while(root){
            if(root->val > key){
                if(root->left && (root->left->val == key)){
                    root->left = toBeDeleted(root->left);
                    break;
                }else root = root->left;
            }else{
                if(root->right && (root->right->val == key)){
                    root->right = toBeDeleted(root->right);
                    break;
                }else root = root->right;
            }
        }return tempRoot;
    }
};
