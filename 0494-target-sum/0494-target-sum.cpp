class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        if (abs(target) > total) return 0;
        if ((target + total) % 2 != 0) return 0;

        int P = (target + total) / 2;

        vector<int> dp(P + 1, 0);
        dp[0] = 1; 

        for (int num : nums) {
            for (int s = P; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }

        return dp[P];
    }
};