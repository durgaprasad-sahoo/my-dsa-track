class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        //this is  the optimal approach for both positives and negatives
        //was hard to understand.
        //15 -2 2 -8 1 7 10 23
        int K = 0;
        int sum = 0;
        int maxLength = 0;
        map<int, int>mpp;
        for(int i=0; i<n; i++){
            
            sum+= A[i];
            if(sum==K) maxLength = max(maxLength, i+1);
            int rem = sum-K;
            if(mpp.find(rem)!=mpp.end()){
                int len = i-mpp[rem];
                maxLength= max(maxLength, len );
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return maxLength;
    }
};
