 User function template for C++

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>>&mat, int n, vector<string>&ans, vector<vector<int>>&visit, int di[], int dj[], string moves){
        
        //basecase
        if(i==n-1 && j==n-1){
            ans.push_back(moves);
            return;
        }
        string directions = "DLRU"; //in lexigraphical order
        
        for(int dirInd = 0; dirInd<4; dirInd++){
            int nexti = i+di[dirInd];
            int nextj = j+dj[dirInd];
            //will first check forward, left, right then upper
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && mat[nexti][nextj]==1 && !visit[nexti][nextj]){
                visit[i][j]=1;
                solve(nexti, nextj, mat, n, ans, visit, di, dj, moves + directions[dirInd]);
            
                visit[i][j]=0;
            }
        }
            
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>visit(n, vector<int>(n, 0));
        //D: i+1, j
        //L: i, j-1
        //R: i, j+1;
        //U: i-1, j
        int di[]={+1, 0, 0, -1};
        int dj[]= {0,-1,+1, 0};
        if(m[0][0]==1){
            solve(0, 0, m, n, ans, visit, di, dj, "");
            
        }return ans;
    }
};
