class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> san;

        for (auto& elem: students) {
            san[elem]++;
        }
        for (auto& elem: sandwiches) {
            if (!san[elem]){
                return san[0] + san[1];
            }
            san[elem]--;
        }

        return 0;
    }
};