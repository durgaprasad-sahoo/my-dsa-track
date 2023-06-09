class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        //bruteForce
        // for(int i=0; i<n; i++){
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     if(!ans.empty() && end <= ans.back()[1]){
        //         continue;
        //     }for(int j=i+1; j<n; j++){
        //         if(intervals[j][0]<=end){
        //             end = max(intervals[j][1], end);
        //         }else{
        //             break;
        //         }
        //     }
        //     ans.push_back({start,end});
        // }
        //optimal
        for(int i=0; i<n; i++){
            if(ans.empty() || intervals[i][0]> ans.back()[1]){
                ans.push_back(intervals[i]);
                //if the array is empty(in first list as it is empty it will be stored in the ans). 
                //or ex: [1,6] is already present in the list. and we compare [8,10] with [1,6]. as 8>6. it'll be another set to be added to the ans.
            }else{
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
