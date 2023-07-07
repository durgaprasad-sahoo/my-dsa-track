vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int>st;
    vector<int>v(A.size(), -1);
    st.push(A[0]);
    for(int i=1; i<A.size(); i++){
        while(!st.empty() && A[i]<=st.top()) st.pop();
        if(!st.empty()) v[i]= st.top();
        st.push(A[i]);
    }return v;
}
