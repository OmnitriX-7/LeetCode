class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i*i <= c; i++){
            long long b = c - i*i;
            long long b1 = sqrt(b);
            if (b1 * b1 == b) return true;
        }
        return false;
    }
};