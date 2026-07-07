class Solution {
public:
    void bfs(vector<vector<int>>& h, vector<vector<bool>>& vis,
        vector<pair<int,int>>& sources)
    {
        int m = h.size();
        int n = h[0].size();

        queue<pair<int,int>> q;

        for(auto &p : sources){
            q.push(p);
            vis[p.first][p.second] = true;
        }

        vector<int> d = {0,1,0,-1,0};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr = r + d[k];
                int nc = c + d[k+1];

                if(nr>=0 && nc>=0 && nr<m && nc<n &&
                   !vis[nr][nc] &&
                   h[nr][nc] >= h[r][c])
                {
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));

        vector<pair<int,int>> pac_src;
        vector<pair<int,int>> atl_src;

        // Pacific borders
        for(int i=0;i<m;i++)
            pac_src.push_back({i,0});

        for(int j=0;j<n;j++)
            pac_src.push_back({0,j});

        // Atlantic borders
        for(int i=0;i<m;i++)
            atl_src.push_back({i,n-1});

        for(int j=0;j<n;j++)
            atl_src.push_back({m-1,j});

        bfs(heights, pac, pac_src);
        bfs(heights, atl, atl_src);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};