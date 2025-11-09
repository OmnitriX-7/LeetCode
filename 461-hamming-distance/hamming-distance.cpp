class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int z = __builtin_popcount(res);
        return z;
    }
};