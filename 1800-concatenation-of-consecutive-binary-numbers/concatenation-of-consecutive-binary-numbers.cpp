class Solution {
public:
    const int MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        long long ans = 0;
        int bitLen = 0;

        for (int num = 1; num <= n; num++) {

            if ((num & (num - 1)) == 0) {
                bitLen++;
            }

            ans = ((ans << bitLen) % MOD + num) % MOD;
        }

        return ans;
    }
};