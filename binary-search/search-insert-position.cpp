class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // //lower bound
        // return lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        int l = 0, h = nums.size()-1;\
        int ans = h+1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]==target) return m;
            else if(target<=nums[m]){
                ans = m;
                h = m-1;
            }else l = m+1;
        }return ans;
    }
};
