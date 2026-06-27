class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> dp(n, 1);     
        vector<int> count(n, 1); 

        int maxLength = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {

                    // Case 1: Found longer subsequence
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }

                    // Case 2: Found another way of same length
                    else if(dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }

            maxLength = max(maxLength, dp[i]);
        }

        int totalCount = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == maxLength) {
                totalCount += count[i];
            }
        }

        return totalCount;
    }

};