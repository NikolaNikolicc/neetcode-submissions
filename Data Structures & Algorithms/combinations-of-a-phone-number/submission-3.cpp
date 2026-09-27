class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string codes[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits == "") return {};
        deque<string> tmp;
        tmp.push_back("");
        for (char digit: digits) {
            int digit_pos = digit - '0';
            int len = tmp.size();
            for (int i = 0; i < len; i++) {
                string left = tmp.front();
                tmp.pop_front();
                for (char d: codes[digit_pos]) {
                    tmp.push_back(left + d);
                }
            }
        }
        return vector(tmp.begin(), tmp.end());
    }
};
