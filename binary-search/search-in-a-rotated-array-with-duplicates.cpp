class Solution {
public:
    int search(vector<int>& nums, int target) {
        //2 5 6 0 0 1 2
        //3 3 1 2 3 3 3
        //always search  in the sorted order first
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return true;
            if(nums[low]== nums[mid] && nums[mid]== nums[high]){
                low++; high--;
                continue;
            }
            // left sorted array
            if(nums[low]<=nums[mid]){
                if(target>= nums[low] && target<=nums[mid]){
                    high = mid-1;
                }else low = mid+1;
            }
            //right sorted array
            else{
                //
                if(target >= nums[mid]&& target<=nums[high]){
                    low = mid+1;
                }else high = mid-1;
            }
        }
        return false;
    }
};

