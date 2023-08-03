class Solution {
private:
    void merge(vector<int>&nums, int s, int m, int e){
        int l = s;
        int r = m+1;
        vector<int>temp;
        while(l<=m and r<=e){
            if(nums[l]<=nums[r]) temp.emplace_back(nums[l++]);
            else temp.emplace_back(nums[r++]);
        }
        while(l<=m) temp.emplace_back(nums[l++]);
        while(r<=e) temp.emplace_back(nums[r++]);
        for(int i=s; i<=e; i++){
            nums[i]= temp[i-s];
        }
    }
    int countPairs(vector<int>&nums, int s, int m, int e){
        int count= 0;
        int r = m+1;
        for(int i=s; i<=m; i++){
            while(r<=e and nums[i] > (2LL* nums[r])){
                r++;
            }count+=(r-(m+1));
        }return count;
    }
    int mergeSort(vector<int>&nums, int s, int e){
        int count=0;
        if(s>=e) return count;
        int m = (s+e)/2;
        count+=mergeSort(nums, s, m);
        count+=mergeSort(nums, m+1, e);
        count+=countPairs(nums, s, m, e);
        merge(nums, s, m, e);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
        
    }
};
