class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto nextIndex = [&](int i){
            return ((i + nums[i]) % n + n) % n;   
        };
        for (int i = 0; i<n; i++){
            if (nums[i] == 0)
            continue;

            bool dir = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {
                int s= nextIndex(slow);
                if (nums[s] == 0 || (nums[s] > 0) != dir)
                break;

                int f = nextIndex(fast);

                if (nums[f] == 0 || (nums[f] > 0) != dir)
                break;

                f = nextIndex(f);

                if (nums[f] == 0 || (nums[f] > 0) != dir)
                break;

                slow = s;
                fast = f;

                if (slow == fast){
                    if (slow == nextIndex(slow))
                    break;

                    return true;
                }
            }

            // Mark current path as visited
            int curr = i;

            while (nums[curr] != 0 && (nums[curr] > 0) == dir) {
                int next = nextIndex(curr);
                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};