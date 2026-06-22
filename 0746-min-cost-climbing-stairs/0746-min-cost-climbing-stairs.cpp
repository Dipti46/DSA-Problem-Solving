class Solution {
public:
    int dp[1001];

    int minCost(int stairs,vector<int>& cost){
        if (stairs < 0) return 0;
        if (stairs == 0) return cost[0];
        if (stairs == 1) return cost[1];

        if (dp[stairs] != -1)
        return dp[stairs];

        int lastStep = cost[stairs] + minCost(stairs-1,cost);
        int secondlastStep = cost[stairs] + minCost(stairs-2,cost);

        return dp[stairs] = min(lastStep,secondlastStep);

    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i=0; i<n; i++)
        dp[i] = -1;

        return min(minCost(n-1,cost),minCost(n-2,cost));
    }
};