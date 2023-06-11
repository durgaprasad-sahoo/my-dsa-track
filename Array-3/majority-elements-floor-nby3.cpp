class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //map
        // int n = nums.size();
        // map<int, int>mpp;
        // vector<int> ans;
        // int floor = (n/3)+1;
        // for(int i=0; i<n; i++){
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]]== floor){
        //         ans.emplace_back(nums[i]);
        //     }
        //     if(ans.size()==2) break;
        // }sort(ans.begin(), ans.end());
        // return ans;

        //Moore's Voting algo modified
        int n= nums.size();
        int candidate1=INT_MIN;
        int candidate2=INT_MIN;
        int votes1=0;
        int votes2=0;
        int floor = (n/3)+1;
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(votes1==0 && nums[i]!=candidate2) {
                votes1=1;
                candidate1=nums[i];
            }
            else if(votes2==0 && nums[i]!=candidate1){
                votes2=1;
                candidate2=nums[i];
            }else if(nums[i]==candidate1){
                votes1++;
            }else if(nums[i]==candidate2){
                votes2++;
            }else{
                votes1--; votes2--;
            }
        }
        int count1=0;
        int count2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==candidate1) count1++;
            if(nums[i]==candidate2) count2++;
        }

        if(count1>=floor) ans.emplace_back(candidate1);
        if(count2>=floor) ans.emplace_back(candidate2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
