class Solution {
private:
    string codes[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
    vector<string> combinations;
    string combination;

    void helper(int pos, string digits){
        if (pos == digits.size()){
            combinations.push_back(combination);
            return;
        }
        int digit = digits[pos] - '0';
        for (char ch: codes[digit]){
            combination += ch;
            helper(pos + 1, digits);
            combination.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int pos = 0;
        if (digits == "")return combinations;
        int digit = digits[pos++] - '0';

        for (char ch: codes[digit]){
            combination = ch;
            helper(pos, digits);
        }
        return combinations;
    }
};
