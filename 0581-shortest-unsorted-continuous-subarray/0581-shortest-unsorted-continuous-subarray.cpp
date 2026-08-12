class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = -1, right = -1;

        // Find the rightmost element that is smaller
        // than the maximum seen so far.
        int maxSeen = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < maxSeen) {
                right = i;
            } else {
                maxSeen = nums[i];
            }
        }

        // Find the leftmost element that is greater
        // than the minimum seen from the right.
        int minSeen = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minSeen) {
                left = i;
            } else {
                minSeen = nums[i];
            }
        }

        if (left == -1)
            return 0;

        return right - left + 1;
    }
};