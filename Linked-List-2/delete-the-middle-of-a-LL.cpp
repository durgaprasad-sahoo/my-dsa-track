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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL) return NULL; 
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* justBeforeSlow = head;
        while(fast and fast->next){
            justBeforeSlow= slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        justBeforeSlow->next = slow->next;
        delete slow;
        return head;
    }
};
