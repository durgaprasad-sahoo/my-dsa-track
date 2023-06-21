class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //0,0,1,1,1,2,2,3,3,4
        //i = 0. val = 0
        //0!=1. i = 1 val = 1
        //1!=2. i = 2 val = 2
        //2!=3. i = 3 val = 3
        //3!=4. i = 4 val = 4
        int i = 0;
        for(int j = 1; j<nums.size(); j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }return i+1;

    }
};
