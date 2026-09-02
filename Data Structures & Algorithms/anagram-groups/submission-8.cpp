class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> letter_counts;
        for (string word : strs){
            int count[26] = {0};
            for (char c : word){
                count[c - 'a']++;
            }
            
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            letter_counts[key].push_back(word);
        }
        vector<vector<string>> res;
        for (const auto&s : letter_counts){
            res.push_back(s.second);
        }
        return res;
    }
};
