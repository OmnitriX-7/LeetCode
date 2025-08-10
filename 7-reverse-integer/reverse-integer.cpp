class Solution {
public:
    int reverse(int x) {
        long long upper = (1LL << 31) - 1;
        long long lower = -(1LL << 31);
 
        long long num = llabs(x);
        long long res = 0;
        while (num > 0) {
            res = res*10 + (num % 10);
            num /= 10;
        }
        if (res > upper || res < lower) return 0;
        if (x < 0) return -res;
        return res;
    }
};