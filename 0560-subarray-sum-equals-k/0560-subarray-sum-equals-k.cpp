class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        mp[0] = 1;   // empty prefix
        
        int sum = 0;
        int count = 0;
        
        for (int num : nums) {
            sum += num;
            
            // Check if a previous prefix sum exists
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            
            // Store current prefix sum
            mp[sum]++;
        }
        
        return count;
    }
};