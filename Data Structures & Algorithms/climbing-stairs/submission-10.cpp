class Solution {
public:
    int climbStairs(int n) {
        if (!n) return 0;
        int one = 0;
        int two = 1;

        for (int i = 1; i <= n; i++){
            int tmp = two;
            two = one + two;
            one = tmp;
        }
        return two;
    }
};
