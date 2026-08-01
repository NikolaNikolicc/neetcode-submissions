class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> positions;

        for (int i = 0; i < numbers.size(); i++) {
            int num = target - numbers[i];
            if (positions.count(num)) {
                return {positions[num] + 1, i + 1};
            }
            positions[numbers[i]] = i;
        }
        return {-1, -1};
    }
};
