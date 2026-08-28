class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (n < totalLen) return ans;

        unordered_map<string, int> need;

        for (string &word : words) {
            need[word]++;
        }

        // Try every possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset;
                 right + wordLen <= n;
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not required
                if (!need.count(word)) {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                window[word]++;
                count++;

                // Too many occurrences of this word
                while (window[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Exactly all words are present
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move window forward for next possible answer
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};