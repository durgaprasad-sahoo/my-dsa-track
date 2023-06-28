class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>&board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                //find if there's a empty place
                if(board[i][j]=='.'){
                    //try all possible elements
                    for(char c = '1'; c<= '9'; c++){
                        if(isValid(c,board, i, j)){
                            board[i][j]= c;
                            //after filling up a  gap move on to the next recusrion call
                            if(solve(board)==true) return true;
                            //if recursion gives false then remove the element and get that space to '.'
                            else board[i][j]='.';
                        }
                    }
                    //if true not returned, a false will be returned.
                    return false;
                }
            }
        }return true;
        //if there is no gap in the line, means there's no true or  false returned earlier. so return a true;
        
    }
    bool isValid(char c, vector<vector<char>>&board, int row, int col){
        for(int i=0; i<9; i++){
            //to check all rows, col will be constant
            if(board[i][col]== c) return false;
            //to check all cols, row will be constant
            if(board[row][i]==c) return false;
            //to check the given row and cols 3x3 matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
            
        }return true;
    }
};
