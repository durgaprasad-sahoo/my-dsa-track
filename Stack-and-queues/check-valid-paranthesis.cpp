class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto it: s){
            if(it == '(' || it == '{' || it == '[') st.push(it);
            else{
                //if the iterator is not a opening bracket and still the stack 
                //is empty it means that the iterator is an closing bracket match with
                //so it won't any other
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if (c=='(' and it == ')' or (c=='{' and it == '}') or (c=='[') and it == ']') continue;
                else return false;
            }
        }
        return st.empty() ? true : false;
    }
};
