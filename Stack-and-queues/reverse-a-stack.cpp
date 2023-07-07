class Solution{
public:

    void insertAtBottom(stack<int>& St, int element){
        if(St.empty()){
            St.push(element);
            return;
        }
        int temp = St.top();
        St.pop();
        insertAtBottom(St, element);
        St.push(temp);
    }
    
    void Reverse(stack<int> &St){
        if(St.empty()) return;
        
        int temp = St.top();
        St.pop();
        
        Reverse(St);
        insertAtBottom(St, temp);
    }
};
