class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int index = -1;
        int N = nums.size();
        for(int i=N-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index= i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(), nums.end());
            return nums;
        }for(int i= N-1;i>index; i--){
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }reverse(nums.begin()+index+1, nums.end());
        return nums;
    }
};
