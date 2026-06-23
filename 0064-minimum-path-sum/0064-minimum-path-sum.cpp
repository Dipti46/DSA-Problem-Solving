class Solution {
public:
    int solve(int right, int down ,vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(right==0 && down==0) return grid[0][0];

        if(right<0 || down<0) return 1e9;

        if(dp[right][down] != -1) return dp[right][down];

        int rightWays = solve(right-1,down,grid,dp);
        int downWays = solve(right,down-1,grid,dp);

        return dp[right][down]= grid[right][down] + min(rightWays,downWays);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return solve(m-1,n-1,grid,dp);
    }
};