//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    // Your Code
    StackNode* temp = new StackNode(x);
    temp->next = top;
    top = temp;
    
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==NULL) return -1;
    int ans = top->data;
    StackNode* temp = top;
    top = top->next;
    delete(temp);
    return ans;
}
