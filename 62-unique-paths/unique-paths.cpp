class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        long long x = m + n - 2;
        long long y = m - 1;

        for (long long i = 1; i <= y; i++) {
            ans = ans * (x-y+i)/i;
        }

        return ans;
    }
};