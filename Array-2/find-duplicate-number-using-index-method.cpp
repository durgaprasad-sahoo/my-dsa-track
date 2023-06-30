class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        //2 3 1 2 3
        //2%5 = 1;
        //2nd index i.e 1+n = 6
        for(int i=0; i<n; i++){
            int index = nums[i]%n;
            nums[index]=nums[index]+n;
        }
        //2 8 11 12 3
        //if arr[i]>=2 then the index is the duplicate number
        for(int i=0; i<n; i++){
            if(nums[i]/n>=2){
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0){ 
            return {-1};
        }
        return ans[0];
    }
};
