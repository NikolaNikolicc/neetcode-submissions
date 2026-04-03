class Solution {
    unordered_map<char, int>  umap;

    int searchMax(){
        int maxFreq = 0;
        for(const auto& pair: umap){
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
    
public:
    int characterReplacement(string s, int k) {
        
        // guaranteed minimum
        int maxLen = min(static_cast<int>(s.size()), k);
        int size = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            umap[s[i]]++;
            size++;

            while (size - searchMax() > k) {
                umap[s[start++]]--;
                size--;
            }
            maxLen = max(maxLen, size);

        }

        return maxLen;
    }
};
