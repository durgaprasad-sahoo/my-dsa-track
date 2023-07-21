class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>windowMax;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front(); //step1: remove out of bounds
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back(); //step2: maintain the decreasing order
            dq.push_back(i); //pushing the current node
            if(i>=k-1) windowMax.push_back(nums[dq.front()]); //if i>k push the front, i.e max to ans;
        }return windowMax;
    }
};
