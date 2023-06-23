class Solution {
public:
    void rec(int index, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
        int n =  nums.size();
        if(index>=n){
            ans.push_back(temp);
            return;
        }
        rec(index+1, nums, temp, ans);
        temp.emplace_back(nums[index]);
        rec(index+1, nums, temp, ans);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        rec(0, nums, temp, ans);
        return ans;
    }
};
