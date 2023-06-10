class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //linear form
        //1 3 5 7 10 11 16 20 23 30 34 60
        //0 1 2 3 4  5  6  7  8  9  10 11
        //s          m                 e
        int row = matrix.size(); //3
        int col = matrix[0].size(); //4
        int start = 0; //0
        int end = row*col-1; //11
        int mid = start+(end-start)/2; //5
        while(start<=end){
           int element = matrix[mid/col][mid%col];
           if(element==target) return true;
           if(element<target) start= mid+1;
           else end= mid-1;
           mid = start+(end-start)/2; 
        } return false;
    }
};
