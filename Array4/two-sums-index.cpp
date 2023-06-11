//better sol using hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //2 7 11 15
        //2 9
        //7 2
        //11 -3
        //15 -6
        int n = nums.size();
        map<int, int>mpp;

        for(int i=0; i<n; i++){
                int firstNum = nums[i];
                int moreNeeded = target-nums[i];
            if(mpp.find(moreNeeded)!=mpp.end()){
                return{i, mpp[moreNeeded]};
                //will return ith index and moreNeeded's value i.e index                
            }mpp[firstNum]=i;
        }
        return {-1,-1};
        
    }
