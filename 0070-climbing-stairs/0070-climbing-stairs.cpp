class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        if (n <= 2) return n;

        if (dp[n] != -1) return dp[n];

        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        return dp[n];
    }

    Solution() {
        for(int i = 0; i < 46; i++)
            dp[i] = -1;
    }
};