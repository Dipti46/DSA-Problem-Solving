class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]=='0') return;

        grid[row][col]='0'; // mark visited

        dfs(row-1,col,grid); // up
        dfs(row+1,col,grid); // down
        dfs(row,col-1,grid); // left
        dfs(row,col+1,grid); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
        
    }
};