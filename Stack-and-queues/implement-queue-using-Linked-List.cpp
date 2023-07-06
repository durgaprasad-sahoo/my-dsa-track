/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    QueueNode* temp = new QueueNode(x);
    if(front==NULL){
        rear = temp;
        front = temp;
        return;
    }
    rear ->next = temp;
    rear = temp;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code  
    if(front==NULL) return -1;
    QueueNode* todelete = front;
    int item = front->data;
    front = front->next;
    delete todelete;
    return item;
}
