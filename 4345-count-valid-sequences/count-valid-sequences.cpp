const int MOD = 1e9+7;
class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

    long long nCr(long long n, long long r) {
        if (n < r || r < 0) return 0;
        if (r == 0 || n == r) return 1;
        if (r > n/2) r = n-r;
        long long num = 1, den = 1;
        for (long long i = 0; i < r; i++) {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        return (num * modInverse(den)) % MOD;
    }

public:
    int countValidSequences(int n, int k) {
        if (k > n) return 0;
        
        long long total = nCr(n-1, k-1);
        
        long long all_odd = 0;
        if ((n-k) % 2 == 0 && n >= k) {
            all_odd = nCr((n+k)/2-1, k-1);
        }
        
        return (total-all_odd+MOD) % MOD;
    }
};