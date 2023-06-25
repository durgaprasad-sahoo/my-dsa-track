class Solution {
public:
    void findCombination(int index, vector<int>& candidates, int target, vector<int>&ds, vector<vector<int>>&ans){
        //base case
        if(target==0){
            ans.emplace_back(ds);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            findCombination(i+1, candidates, target-candidates[i], ds, ans);
            //remove last elemenet from the data structure
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        //1 1 2 5 6 7 8
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, candidates, target, ds, ans);
        return ans;

    }
};
