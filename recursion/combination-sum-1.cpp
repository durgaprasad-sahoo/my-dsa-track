class Solution {
public:
    void findCombination(int index, vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&ds){
        //basecase
        if(index==candidates.size()){
            if(target==0) ans.emplace_back(ds);
            return;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            findCombination(index, candidates, target-candidates[index], ans, ds);
            ds.pop_back();
        }
        findCombination(index+1, candidates, target, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, candidates, target, ans, ds);
        return ans;
    }
};
