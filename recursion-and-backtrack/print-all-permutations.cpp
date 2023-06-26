class Solution {
public:
    void rec(int index, vector<int>&nums, vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums); 
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            rec(index+1, nums, ans);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        rec(0, nums, ans);
        return ans;
    }
};
