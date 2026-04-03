class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        unordered_set<char> uset;
        int start = 0;
        for (int i = 0; i < s.size(); i++){
            while (uset.count(s[i])){
                uset.erase(s[start++]);
            }
            uset.insert(s[i]);
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
