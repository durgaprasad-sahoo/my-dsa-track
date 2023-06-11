class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int>mpp;
        // int n= nums.size();
        // for(int i=0; i<n; i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it : mpp){
        //     if(it.second> (n/2)){
        //         return it.first;
        //     }
        // }return -1;

        //Moore's voting algorithm
        int n = nums.size();
        int candidate;
        int votes=0;
        //here we'll find the candidate key i.e the max
        for(int i=0; i<n; i++){
            if(votes==0){
                votes = 1;
                candidate = nums[i];
            }else{
                if(nums[i]==candidate){
                    votes++;
                }else{
                    votes--;
                }
            }
        }
        //check the count of the candidate key
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==candidate){
                count++;
            }
        }
        //check if candidate's count is greater than n/2
        if(count> (n/2)) return candidate;
        return -1;
    }
};
