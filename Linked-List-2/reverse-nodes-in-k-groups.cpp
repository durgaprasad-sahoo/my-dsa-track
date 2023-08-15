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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* forward = NULL;
        int totalNodes=0;
        while(temp){
            totalNodes++;
            temp = temp->next;
        }
        int count=0;
        if(totalNodes>=k){
            while(curr and count<k){
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                count++;
            }
            if(forward) head->next = reverseKGroup(forward, k);
        }else return head;
        return prev;
    }
};
