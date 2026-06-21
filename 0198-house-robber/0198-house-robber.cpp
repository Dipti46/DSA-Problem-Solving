class Solution {
public:
    int dp[1001];

    int maxMoney(int houses , vector<int>& nums){
        if (houses < 0) return 0;
        if (houses == 0) return nums[0];

        if (dp[houses] != -1) return dp[houses];

        int steal = nums[houses] + maxMoney(houses-2,nums);
        int skip = maxMoney(houses-1,nums);

        return dp[houses] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++)
        dp[i] = -1;

        return maxMoney(n-1,nums);
    }
};