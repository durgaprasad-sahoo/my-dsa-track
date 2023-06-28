class Solution {
public:
    int search(vector<int>& nums, int target) {
        //ex0:  1 2 3 4 5 6 7;
        // ex1: 4 5 6 7 0 1 2;
        // ex2: 5 6 0 1 2 3 4;
        // ex3: 6 7 1 2 3 4 5;

        //always search  in the sorted order first
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            // left sorted array
            if(nums[low]<=nums[mid]){
                if(target>= nums[low] && target<=nums[mid]){
                    high = mid-1;
                }else low = mid+1;
            }
            //right sorted array
            else if(nums[low]>nums[mid]){
                //
                if(target >= nums[mid]&& target<=nums[high]){
                    low = mid+1;
                }else high = mid-1;
            }
        }
        return -1;
    }
};



