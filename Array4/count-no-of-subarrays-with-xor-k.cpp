int Solution::solve(vector<int> &A, int B) {
    //bruteForce
    // int n = A.size();
    // int count = 0;
    // for(int i=0; i<n; i++){
    //     int xorr = 0;
    //     for(int j=i; j<n; j++){
    //         xorr = xorr ^ A[j];
    //         if(xorr== B) count++;
    //     }
    // }return count;
    
    
    
    //4 2 2 6 4
    //xorr = x^B
    //x = xorr ^ B
    int n = A.size();
    int xorr = 0;
    unordered_map<int,int>mpp;
    mpp[xorr]++; // initialises the map with {0,1} at first;
    int count = 0;
    for(int i=0; i<n; i++){
        xorr = xorr ^ A[i];
        int x = xorr ^ B;
        if(mpp.find(x)!=mpp.end()) count+= mpp[x]; //checks if x present at map then add it's value. i.e count to the count;
        //can also be written as 
        //count+= mpp[x]; means if x is not present in map then it'll be automatically 0 otherwise return the value;
        mpp[xorr]++;
    }return count;
      
}
