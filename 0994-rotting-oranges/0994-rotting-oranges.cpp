class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int fresh){
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        

        while(!q.empty()){
            int sq = q.size();
            bool thisTimeRotten = false;

            for(int i=0; i<sq; i++){
                auto[x,y] = q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                        thisTimeRotten = true;
                    }
                } 
            }  
            if(thisTimeRotten) time++;              
        }
        if(fresh==0){
            return time;
        } else return -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        return bfs(grid,q,fresh);
    }
};