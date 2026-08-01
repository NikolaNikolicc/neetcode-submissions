class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> umap;
        int cnt = 0, res = 0, mf = 0, l = 0;
        for (int i = 0; i < s.size(); i++) {
            umap[s[i]]++;
            cnt++;
            mf = max(mf, umap[s[i]]);
            if (cnt - mf > k) {
                umap[s[l++]]--;
                cnt--;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};
