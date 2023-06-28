class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        //5 7 7 8 8 10
        //lower bound will be the first occurence
        //upper bound will be here  10. so last occurence will be upper bound-1
        int lb = lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        int last_occurence = upper_bound(nums.begin(), nums.end(), target)- nums.begin()-1;
        if(lb == nums.size() || nums[lb]!= target){
            ans.push_back(-1);
            ans.push_back(-1);
        }else{
            ans.push_back(lb);
            ans.push_back(last_occurence);
        }
        return ans;

        //method 2: using binary search twice.
        //first search  will search for first occurence from mid towards low. so when nums[mid]==target
        //along  with first = mid, do high = mid-1;
        //second search  will search for last occurence from mid towards high. so when nums[mid]==target
        //along  with first = mid, do low = mid+1;
    }
};
