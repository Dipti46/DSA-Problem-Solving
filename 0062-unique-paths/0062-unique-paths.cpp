class Solution {
public:
    int numPaths(int right,int down,vector<vector<int>>& dp){
        if (right==0 && down==0) return 1;
        if (right<0 || down<0) return 0;
        if (dp[right][down] != -1) return dp[right][down];

        int rightStep = numPaths(right-1,down,dp);
        int downStep = numPaths(right,down-1,dp);

        return dp[right][down] = rightStep + downStep;

    }
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m, vector<int>(n,-1));

      return numPaths(m-1,n-1,dp);
    }
};