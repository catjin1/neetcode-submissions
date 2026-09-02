class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differences;
        for (int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if (differences.contains(difference)){
                return {differences[difference], i};
            }
            differences[nums[i]] = i;
        }
        return {};
    }
};
