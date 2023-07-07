class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n =  nums1.size();
        int m = nums2.size();
        unordered_map<int, int>mp;
        stack<int>st;
        for(int i=m-1; i>=0; i--){
            if(st.empty()){ // if stack is empty, means there's no number greater than this,
                mp[nums2[i]]=-1; //so make it's value as -1 and add to stack
                // st.push(nums2[i]);
            }else if(!st.empty() && nums2[i]< st.top()){
                mp[nums2[i]]= st.top();
                // st.push(nums2[i]);
            }else if(!st.empty() && nums2[i]>st.top()){
                while(!st.empty() && nums2[i]>st.top())  st.pop();
                if(!st.empty()) mp[nums2[i]]=st.top();
                else mp[nums2[i]]=-1;
                // st.push(nums2[i]);
            }
            st.push(nums2[i]);
        }
        vector<int>ans(n,0);
        for(int i=0; i<n; i++){
            ans[i]= mp[nums1[i]];
        }
        return ans;

    }
};
