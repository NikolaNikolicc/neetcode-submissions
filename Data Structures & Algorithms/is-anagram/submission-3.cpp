class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        int cnt = s.size();
        for (char c: s) {
            umap[c]++;
        }
        for (char c: t) {
            if (umap[c] > 0) {
                umap[c]--;
                cnt--;
            } else return false;
        }
        return cnt == 0;
    }
};
