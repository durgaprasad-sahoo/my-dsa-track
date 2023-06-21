/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        //step 1
        while(temp!=NULL){
            Node* deepCopy = new Node(temp->val);
            deepCopy->next = temp->next;
            temp->next = deepCopy;
            temp = temp->next->next;
        }

        //step 2;

        Node* itr =head;
        while(itr!=NULL){
            if(itr->random != NULL)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }

        //step 3
        Node* dummy =  new Node(0);
        itr = head;
        temp = dummy;
        Node* forward;
        while(itr != NULL){
            forward = itr->next->next;
            temp->next = itr->next;
            itr->next = forward;
            temp = temp->next;
            itr = forward;
        }return dummy->next;
    }
};
