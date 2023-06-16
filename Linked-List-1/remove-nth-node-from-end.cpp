/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr= curr->next;
        }
        int pointer = count-n;
        if(pointer==0){
            ListNode* newHead = head->next;
            head->next = NULL;
            delete head;
            return newHead;
        }
        curr = head;
        for(int i=1; i<pointer; i++){
            if(curr-> next != NULL){
                curr = curr->next;
            }
            
        } 
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};
