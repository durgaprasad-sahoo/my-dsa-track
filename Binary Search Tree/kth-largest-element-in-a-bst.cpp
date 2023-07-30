class Solution{
private:
    void find(Node* root, int k, int& ans, int& count){
        if(!root) return;
        find(root->right, k, ans, count);
        count++;
        if(count==k){
            ans = root->data;
            return;
        }
        find(root->left, k, ans, count);
    }
public:
    int kthLargest(Node *root, int K){
        //Your code here
        int ans=0;
        int count=0;
        find(root, K, ans, count);
        return ans;
    }
};
