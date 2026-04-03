class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        umap[0] = 1;
        int res = 0;
        int csum = 0;
        for (int num: nums){
            csum += num;
            res += umap[csum - k];
            umap[csum]++;
        }
        return res;
    }
};