class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.size() == 0) return arr;
        int lastIdx = arr.size() - 1;
        int maxElem = arr[lastIdx];
        arr[lastIdx] = -1;
        for (int pos = lastIdx - 1; pos > -1; pos--) {
            int prev = maxElem;
            maxElem = max(arr[pos], maxElem);
            arr[pos] = prev;
        }
        return arr;
    }
};