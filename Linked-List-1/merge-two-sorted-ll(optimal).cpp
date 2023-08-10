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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val > list2->val) swap(list1, list2); //the minimum num should start from list1
        ListNode* ansNode = list1;
        while(list1 and list2){
            ListNode* temp = NULL;
            while(list1 and list1->val <= list2->val){
                temp = list1;
                list1= list1->next;
            }temp->next = list2;
            swap(list1, list2);
        }return ansNode;
    }
};
