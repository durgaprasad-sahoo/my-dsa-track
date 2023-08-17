
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* mergeTwoLists(Node* a, Node* b){
    Node* temp = new Node(0);
    Node* ansNode = temp;
    while(a and b){
        if(a->data < b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a) temp->bottom = a;
    else temp->bottom = b;
    
    return ansNode->bottom;
}
Node *flatten(Node *root){
    //base case
    if(!root or root->next == NULL)  return root;
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}
