//doubly linked list
class Node{
    public:
    int key;
    int val;

    Node* prev;
    Node* next;

    //constructor
    Node(int _key, int _val){
        key = _key;
        val = _val;
    }
};
class LRUCache {
public:
    //setting the dummy head and tail of the doubly linked list
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1,-1);
    //order: recent used to least used(left to right). (head  to tail)
    int cacheCapacity;
    unordered_map<int, Node*>mpp;

    LRUCache(int capacity) {
        cacheCapacity = capacity;
        //connecting the head and tail;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* nodeToBeAdded){
        Node* temp = head->next;
        nodeToBeAdded->next  = temp;
        nodeToBeAdded->prev = head;
        head->next = nodeToBeAdded;
        temp->prev = nodeToBeAdded;
    }

    void deleteNode(Node* nodeToBeDeleted){
        Node* delsPrev = nodeToBeDeleted->prev;
        Node* delsNext = nodeToBeDeleted->next;
        delsPrev->next = delsNext;
        delsNext->prev = delsPrev;
    }

    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* ansNode = mpp[key]; // get the address of the node from the hashmap
            int ans = ansNode->val; //store the value of the node in ans
            mpp.erase(key); //remove the key and it's value from the hashmap
            deleteNode(ansNode); //delete the ansNode as it is use recently, so it's not a least node anymore
            addNode(ansNode); //as the node is a recent node, add the ansNode after the head;
            mpp[key] = head->next; //as the node's key and value i.e address was deleted from the hashmap. after adding in the LL,
            //  a new address will be created. so add the new Key and value in the hashmap
            return ans;
        }return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){   //if already exists in the cache
            Node* existingNode = mpp[key];  //get it's address from the hashmap
            mpp.erase(key); //erase the hashmap
            deleteNode(existingNode); //delete the existing node from the LL

        }
        if(mpp.size()==cacheCapacity){
            mpp.erase(tail->prev->key); //remove the last node's key and value in the hashmap
            deleteNode(tail->prev);
        }
        //adding the node after the head
        addNode(new Node(key, value));
        mpp[key]= head->next; //keeping the track of the new node in the hashmap
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
