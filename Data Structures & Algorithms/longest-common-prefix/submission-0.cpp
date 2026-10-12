class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        int start = 0, end = strs[0].size();

        for (int j = 1; j < strs.size(); j++) {
            string s = strs[j];
            int i = 0;
            while (i < end && i < s.size() && strs[0][i] == s[i]) {
                i++;
            }
            end = i;
        }

        return strs[0].substr(0, end);
    }
};