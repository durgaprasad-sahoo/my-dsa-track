class Solution
{
public:
    void findSubsetSums(int index, int sum, vector<int>& ans, vector<int>&arr, int N){
        if(index==N){
            ans.emplace_back(sum);
            return;
        }
        findSubsetSums(index+1, sum+ arr[index], ans, arr, N);
        findSubsetSums(index+1, sum, ans, arr, N);
        
    }
public:

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        int sum;
        findSubsetSums(0, 0, ans, arr, N);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
