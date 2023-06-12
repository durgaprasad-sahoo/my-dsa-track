//bruteForce
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        sort(nums.begin(), nums.end());
        //1 2 3 4 100 200

        int prev = nums[0];
        int longestYet= 1;
        int currentLongest = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i]==prev+1) currentLongest++;
            else if(nums[i]!=prev) currentLongest=1;
            prev = nums[i];
            longestYet = max(longestYet, currentLongest);
        }
        return longestYet;
    }
};
