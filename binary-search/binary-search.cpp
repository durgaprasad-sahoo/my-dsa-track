class Solution {
public:
    int binSearch(int low, int high, vector<int>&nums, int target){
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(target== nums[mid]) return mid;
        else if(target<nums[mid]){
            return binSearch(low, mid-1, nums, target);
        }
        return binSearch(mid+1, high, nums, target);
    }
public:
    int search(vector<int>& nums, int target) {
        int ans = binSearch(0, nums.size()-1, nums, target);
        return ans;
    }
};
