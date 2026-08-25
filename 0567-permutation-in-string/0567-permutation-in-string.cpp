class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1)
            freq1[c - 'a']++;

        int k = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;

            // Window size > k
            if (i >= k)
                freq2[s2[i - k] - 'a']--;

            // Window size == k
            if (i >= k - 1 && freq1 == freq2)
                return true;
        }

        return false;
    }
};