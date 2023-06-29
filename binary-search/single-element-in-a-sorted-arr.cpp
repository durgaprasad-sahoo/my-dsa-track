class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        //1 1 2 3 3 4 4 8 8
        //e o e o e o e o e
        //before the single element: matching pairs are in even odd order
        //after the single element: matching pairs are in odd even order
        if(nums[0]!= nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        //check the first and last index and trim the search size
        int low = 1, high = n-2;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]){
                return nums[mid];
            }
            if(mid%2==1 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1]){
                low= mid+1; //eliminate left half
            }else{
                high = mid-1; //eliminate right half
            }
        }
        return -1;
    }
};
