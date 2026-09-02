class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> letter_counts;
        letter_counts.reserve(strs.size());

        for (string& word : strs) {          // reference, avoid copying into loop var
            int count[26] = {0};
            for (char c : word) {
                count[c - 'a']++;
            }

            string key(26, '\0');
            for (int i = 0; i < 26; i++) {
                key[i] = static_cast<char>(count[i]);
            }

            letter_counts[key].push_back(std::move(word));
        }

        vector<vector<string>> res;
        res.reserve(letter_counts.size());
        for (auto& [key, group] : letter_counts) {
            res.push_back(std::move(group));
        }
        return res;
    }
};