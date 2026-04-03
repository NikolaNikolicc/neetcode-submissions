class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> accLeft(ratings.size(), 0);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                accLeft[i] = accLeft[i - 1] + 1;
            }
        }
        vector<int> accRight(ratings.size(), 0);
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                accRight[i] = accRight[i + 1] + 1;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < ratings.size(); i++) {
            sum += max(accLeft[i], accRight[i]);
        }
        sum += ratings.size();
        return sum;
    }
};