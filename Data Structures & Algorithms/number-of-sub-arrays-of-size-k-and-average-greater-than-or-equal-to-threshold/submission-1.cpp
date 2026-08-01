class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, res = 0;

        for (int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if (i >= k - 1) {
                if (i >= k) sum -= arr[i - k];
                if ((double)sum / (double)k >= threshold) res++;
            }
        }
        return res;
    }
};