class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); //nums of rows
        int m = grid[0].size(); //nums of ci=ols
        queue<pair<pair<int, int>, int>>q;
        // int visited[n][m]; //visited array  to keep track
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0}); //pushing the initial rotten oranges index with initial time as 0 to queue;
                    visited[i][j]=2;
                }
            }
        }
        int time=0;
        int deltaRow[]={-1,0,1,0};
        int deltaCol[]= {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c= q.front().first.second;
            int t = q.front().second;
            time = max(t, time);
            q.pop();
            for(int i=0; i<4; i++){
                int neighbouringRow = r+deltaRow[i];
                int neighbouringCol = c+deltaCol[i];
                if(neighbouringRow >=0 && neighbouringRow <n && neighbouringCol >= 0  && neighbouringCol< m && visited[neighbouringRow][neighbouringCol]!=2 && grid[neighbouringRow][neighbouringCol]==1){
                    q.push({{neighbouringRow, neighbouringCol}, t+1});
                    visited[neighbouringRow][neighbouringCol]=2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
