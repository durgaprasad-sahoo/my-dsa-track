int findCeil(Node* root, int input) {
    int ceil = -1;
    if (root == NULL) return ceil;
    
    while(root){
        if(root->data == input){
        ceil = root->data;
        return ceil;
        }
        if(input > root->data){
            root = root->right;
        }else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
