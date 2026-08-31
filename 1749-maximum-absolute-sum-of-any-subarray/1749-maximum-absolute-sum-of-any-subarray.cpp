class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = 0;
        int minEnding = 0;
        int maxSum = 0;
        int minSum = 0;

        for (int x : nums) {
            maxEnding = max(0, maxEnding + x);
            minEnding = min(0, minEnding + x);

            maxSum = max(maxSum, maxEnding);
            minSum = min(minSum, minEnding);
        }

        return max(maxSum, -minSum);
    }
};