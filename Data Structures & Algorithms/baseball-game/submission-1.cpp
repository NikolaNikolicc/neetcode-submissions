class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        for (auto& op: operations) {
            if (op == "+") {
                int e1 = records.top(); records.pop();
                int e2 = records.top(); records.pop();
                records.push(e2);
                records.push(e1);
                records.push(e1 + e2);
            } else if (op == "D") {
                records.push(records.top() * 2);
            } else if (op == "C") {
                records.pop();
            } else {
                records.push(stoi(op));
            }
        }
        int res = 0;
        while (!records.empty()) {
            res += records.top(); records.pop();
        }
        return res;
    }
};