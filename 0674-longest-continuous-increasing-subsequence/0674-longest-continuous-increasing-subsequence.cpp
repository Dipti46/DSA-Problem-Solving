class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;

        int current = 1;
        int maxi = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] > nums[i-1]) {
                current++;
            } else {
                current = 1;
            }

            maxi = max(maxi, current);
        }

        return maxi;
    }
};