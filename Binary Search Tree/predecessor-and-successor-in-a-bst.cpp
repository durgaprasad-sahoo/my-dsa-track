class Solution{
private:
    Node* succ(Node* root, Node*& suc, int num){
        while(root){
            if(num >= root->key) root = root->right;
            else{
                suc = root;
                root = root->left;
            }
        }return suc;
    }
    Node* pred(Node* root, Node*& pre, int num){
        while(root){
            if(num <= root->key) root = root->left;
            else{
                pre = root;
                root = root->right;
            }
        }return pre;
    }
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
        // Your code goes here
        suc = NULL;
        pre = NULL;
        succ(root, suc, key);
        pred(root, pre, key);
    }
};
