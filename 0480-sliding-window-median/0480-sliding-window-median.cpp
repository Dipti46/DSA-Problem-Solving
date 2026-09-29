class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> low, high;
        vector<double> ans;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                high.insert(*it);
                low.erase(it);
            }

            while (low.size() < high.size()) {
                auto it = high.begin();
                low.insert(*it);
                high.erase(it);
            }
        };

        auto add = [&](long long x) {
            if (low.empty() || x <= *prev(low.end()))
                low.insert(x);
            else
                high.insert(x);

            balance();
        };

        auto remove = [&](long long x) {
            auto it = low.find(x);

            if (it != low.end())
                low.erase(it);
            else {
                it = high.find(x);
                high.erase(it);
            }

            balance();
        };

        // First window
        for (int i = 0; i < k; i++)
            add(nums[i]);

        // Median of first window
        if (k % 2)
            ans.push_back(*prev(low.end()));
        else
            ans.push_back((*prev(low.end()) + *high.begin()) / 2.0);

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            remove(nums[i - k]);
            add(nums[i]);

            if (k % 2)
                ans.push_back(*prev(low.end()));
            else
                ans.push_back((*prev(low.end()) + *high.begin()) / 2.0);
        }

        return ans;
    }
};