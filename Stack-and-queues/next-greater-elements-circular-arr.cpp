class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //4 12 5 3 1 2 5 3 1 2 4 6
        int n = nums.size();
        stack<int>st;
        vector<int>nge(n,-1); 
        for(int i= 2*n-1; i>=0; i--){ // considering an imaginary copy array of the first array
            while(!st.empty() && nums[i%n]>= st.top()) st.pop(); //if element in array is larger than the top of stack then remove those smaller  numbers  that are in the top of the stack
            if(!st.empty() && i<n) nge[i] = st.top(); //if the array is still not empty and the index lies in the first array then the top will be the next greater number to the number
            st.push(nums[i%n]);
        }
        return nge;
    }
};
