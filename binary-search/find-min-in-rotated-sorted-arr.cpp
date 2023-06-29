class Solution {
public:
    int findMin(vector<int>& nums) {
        //4 5 6 7 0 1 2
        int low = 0, high = nums.size()-1, ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            //check the sorted side first and take the min from this side first then eleminate the sorted array and check its min with the other sides min
            if(nums[low]<=nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};
