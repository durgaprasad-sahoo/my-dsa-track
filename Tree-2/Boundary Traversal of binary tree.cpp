/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
    void leftTraversal(Node* root, vector<int>&ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)) return;
        ans.emplace_back(root->data);
        if(root->left) leftTraversal(root->left,ans);
        else leftTraversal (root->right, ans);
    }
    
    void leafsTraversal(Node* root, vector<int>&ans){
        //inorder traversal to find leafs
        if(root==NULL) return;  //base case
        if(root->left==NULL && root->right==NULL){
            ans.emplace_back(root->data);
            return;
        }
        leafsTraversal(root->left, ans);
        leafsTraversal(root->right, ans);
    }
    
    void rightTraversal(Node* root, vector<int>&ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)) return;
        if(root->right) rightTraversal(root->right, ans);
        else rightTraversal(root->left, ans);
        ans.emplace_back(root->data); //printing while returning back
    }
public:
    vector <int> boundary(Node *root){
        vector<int>ans;
        if(root==NULL) return ans;
        ans.emplace_back(root->data);
        leftTraversal(root->left, ans);
        leafsTraversal(root->left,ans);
        leafsTraversal(root->right, ans);
        rightTraversal(root->right, ans);
        return ans;
    }
};
