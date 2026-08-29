class Solution {
public:
    int maximumSum(vector<int>& arr) {
        long long noDel = arr[0];
        long long oneDel = -1e18;
        long long ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            long long newOneDel = max(oneDel + arr[i], noDel);
            long long newNoDel = max((long long)arr[i], noDel + arr[i]);

            noDel = newNoDel;
            oneDel = newOneDel;

            ans = max({ans, noDel, oneDel});
        }

        return (int)ans;
    }
};