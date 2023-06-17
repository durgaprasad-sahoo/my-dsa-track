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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL || k==0) return head;
        ListNode* curr = head;
        int len = 1;
        while(curr->next!=NULL){
            len++;
            curr = curr->next;
        }
        //connect last node to the first node.
        curr ->next = head;
        //if k is greater than len. must get  it back to it's original size.
        //example: len =5, k= 10. LL won't change
        //example: len = 5, k = 12. LL will move 2 position towards right.
        k = k%len;
        int end = len-k;
        while(end--){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
