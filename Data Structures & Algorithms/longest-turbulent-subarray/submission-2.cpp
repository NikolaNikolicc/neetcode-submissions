class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2){
            return arr.size();
        }
        
        int res = 1;
        bool stateBigger = (arr[1] > arr[0]);
        int start = 0;
        for (int curr = 1; curr < arr.size(); curr++){
            if (stateBigger && arr[curr] > arr[curr - 1] || !stateBigger && arr[curr] < arr[curr - 1]){
                stateBigger = !stateBigger;
                res = max(curr - start + 1, res);
            } else if (arr[curr] == arr[curr - 1]) {
                start = curr;
                if (curr + 1 < arr.size()){
                    stateBigger = (arr[curr + 1] > arr[curr]);
                }
            } else {
                // exception
                start = curr - 1;
                stateBigger = (arr[curr - 1] > arr[curr]);
            }
        }
        return res;
    }
};