class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count=0;
        int startRow = 0;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        while(count < (row*col)){
            //startRow
            for(int i=startCol; count < row*col and i<=endCol; i++){
                ans.emplace_back(matrix[startRow][i]); count++;
            }startRow++;
            //endCol
            for(int i= startRow; count < row*col and i<=endRow; i++){
                ans.emplace_back(matrix[i][endCol]); count++;
            }endCol--;
            //endRow
            for(int i=endCol; count < row*col and i>=startCol; i--){
                ans.emplace_back(matrix[endRow][i]); count++;
            }endRow--;
            //startCol
            for(int i=endRow; count < row*col and i>=startRow; i--){
                ans.emplace_back(matrix[i][startCol]); count++;
            }startCol++;
        }return ans;
    }
};
