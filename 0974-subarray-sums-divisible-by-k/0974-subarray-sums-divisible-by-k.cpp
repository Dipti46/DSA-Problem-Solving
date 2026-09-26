class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;

        int prefix = 0;
        int ans = 0;

        for (int num : nums) {
            prefix += num;

            int rem = prefix % k;

            // Handle negative remainder
            if (rem < 0)
                rem += k;

            ans += freq[rem];
            freq[rem]++;
        }

        return ans;
    }
};