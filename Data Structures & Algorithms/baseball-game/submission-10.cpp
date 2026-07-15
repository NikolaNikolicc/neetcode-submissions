#include <stack>

using namespace std;

class Solution {
public:
    int read(stack<string>& record) {
        string elem = record.top();
        record.pop();
        return stoi(elem);
    }

    int calPoints(vector<string>& operations) {
        stack<string> record;
        for (string& op: operations) {
            if (op == "+") {
                int elem1 = read(record);
                int elem2 = read(record);
                record.push(to_string(elem2));
                record.push(to_string(elem1));
                record.push(to_string(elem1 + elem2));
            } else if (op == "D") {
                int elem = stoi(record.top());
                record.push(to_string(2 * elem));
            } else if (op == "C") {
                record.pop();
            } else {
                record.push(op);
            }
        }
        int res = 0;
        while (record.size()) {
            res += read(record);
        }
        return res;
    }
};