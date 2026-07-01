class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        if (total % 2 != 0) return false;

        int target = total / 2;

        bitset<10001> dp;
        dp[0] = 1;

        for (int num : nums) {
            dp = dp | (dp << num);
        }

        return dp[target];
    }
};