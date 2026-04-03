class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::unordered_map<int, int> umap;

        for (int elem: nums){
            umap[elem]++;
        }
        
        int pos = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < umap[i]; j++){
                nums[pos++] = i;
            }
        }
    }
};