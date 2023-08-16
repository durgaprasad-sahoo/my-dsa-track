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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int>st;
        int maxi = INT_MIN;
        while(fast and fast->next){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow){
            int temp = st.top() + slow->val;
            maxi = max(maxi, temp);
            slow = slow->next;
            st.pop();
        }return maxi;
    }
};
