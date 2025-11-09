class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start ^ goal;
        int z = __builtin_popcount(res);
        return z;
    }
};