class Solution {
public:
    int arrangeCoins(int n) {
        long long p = 0;
        long long q = n;
        long long ans = 0;
        while (p <= q) {
            long long mid = p + (q-p)/2;
            long long sum = mid*(mid+1)/2;
            if (sum == n) {
                ans = mid;
                break;
            }
            else if (sum > n) {
                q = mid-1;
            }
            else {
                ans = mid;
                p = mid+1;
            }
        }
        return ans;
    }
};