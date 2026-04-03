class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;

        for (auto& op: operations) {
            if (op == "C") {
                if (records.size()) {
                    records.pop_back();
                } else {
                    return -1;
                }
            } else if (op == "D") {
                if (records.size()) {
                    records.push_back(records.back() * 2);
                } else {
                    return -1;
                }
            } else if (op == "+") {
                if (records.size() > 1) {
                    int l = records.size();
                    records.push_back(records[l - 1] + records[l - 2]);
                } else {
                    return -1;
                }
            } else {
                records.push_back(stoi(op));
            }
        }

        int sum = 0;
        for (auto& elem: records) {
            sum += elem;
        }

        return sum;
    }
};