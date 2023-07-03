int countElementsLessThanMid(vector<int>row, int mid){
    int cols = row.size();
    
    int low = 0;
    int high = cols-1;
    while(low<=high){
        // 1 3 5    mid = 500
        //how many numbers less than 500 are in the row
        int md = (low+high) >> 1;
        if(row[md]<= mid) low = md+1;
        else high = md-1;
    }return low;
    
}
int Solution::findMedian(vector<vector<int> > &A) {
    int N = (A.size() * A[0].size());
    int low = 1;
    int high = 1e9;
    //the range of the search space is 1 to 10^9;
    while(low<=high){
        int mid = (low+high) >> 1;
        int count = 0;
        for(int i=0; i<A.size(); i++){
            //for loop to count all the elements  less than the mid in the matrix
            //here i denotes each row of the matrix
            count += countElementsLessThanMid(A[i], mid);
        }
        if(count<=N/2) low = mid+1;
        else high = mid-1;
    }return low;
}
