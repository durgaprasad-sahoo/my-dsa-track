class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<int>st;
        for(auto i:s){
            if(i=='('){
                if(!st.empty()) ans.push_back(i);
                st.push(i);
            }else{
                st.pop();
                if(!st.empty()) ans.push_back(i);
            }
        }
        return ans;
    }
};
