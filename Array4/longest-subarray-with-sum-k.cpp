//this is  the optimal approach for both positives and negatives
//was hard to understand.
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        // {15,-2,2,-8,1,7,10,23}
        int maxLength = 0;
        int key = 0;
        int sum = 0;
        unordered_map<int,int>mpp;
        for(int i=0; i<n; i++){
            sum+= A[i];
            int rem = sum-key;
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
                //if sum is not present in the map then put both sum and index till which the sum is. in the map
            }
            
            if(mpp.find(rem)!=mpp.end()){
                int length = i-mpp[rem]; // will return the subarray's length whose sum = k;
                maxLength = max(maxLength,length); 
                //example: -2 and -2 are in max Length earlier i.e 2.
                //later -2 2 -8 1 7's length gets to be 5. comparing it with maxLength
            }
            if(sum==key){
                maxLength =max(maxLength, i+1);
                //example: 1 2 3 key = 3
                //1 and 2's sum was key and was already present in map. whose length was 2
                //now 3 == key whose length is 1. so check.
                
            }
            
        }
        return maxLength;
    }
};
