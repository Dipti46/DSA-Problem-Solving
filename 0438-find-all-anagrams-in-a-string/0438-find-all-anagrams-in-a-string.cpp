class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        vector<int> countP(26, 0);
        vector<int> countS(26, 0);

        // Frequency of characters in p
        for (char c : p) {
            countP[c - 'a']++;
        }

        int k = p.size();

        // First window
        for (int i = 0; i < k; i++) {
            countS[s[i] - 'a']++;
        }

        if (countS == countP)
            ans.push_back(0);

        // Sliding window
        for (int i = k; i < s.size(); i++) {

            // Add new character
            countS[s[i] - 'a']++;

            // Remove character leaving window
            countS[s[i - k] - 'a']--;

            // Check anagram
            if (countS == countP)
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};