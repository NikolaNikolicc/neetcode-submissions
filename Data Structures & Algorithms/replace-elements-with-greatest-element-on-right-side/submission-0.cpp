class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int carry = -1, tmp = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            tmp = arr[i];
            arr[i] = carry;
            carry = max(carry, tmp);
        }
        return arr;
    }
};