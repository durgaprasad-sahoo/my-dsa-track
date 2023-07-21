class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int leftSmallNums[n];
        int rightSmallNums[n];
        
        for(int i=0; i<n; i++){
            while(!st.empty()&& heights[st.top()] >= heights[i]){
                st.pop();
            }if(st.empty()) leftSmallNums[i]= 0;
            else leftSmallNums[i]= st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i= n-1; i>=0; i--){
            while(!st.empty()&& heights[st.top()]>= heights[i]){
                st.pop();
            }
            if(st.empty()) rightSmallNums[i]= n-1;
            else rightSmallNums[i]=st.top()-1;
            st.push(i);
        }
        int lar=0;
        for(int i=0; i<n; i++){
            lar = max(lar, (rightSmallNums[i]-leftSmallNums[i]+1)* heights[i]);
        }return lar;
    }
};
