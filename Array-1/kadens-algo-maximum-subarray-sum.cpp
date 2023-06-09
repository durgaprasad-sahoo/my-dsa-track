class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        int maxi = nums[0];
        for(int i=0; i<N; i++){
            sum+=nums[i];
            maxi = max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }return maxi;
    }
};
