class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = 50*1e9;
        long long ans = 0;

        while (lo <= hi) {
            long long mid = lo + (hi-lo)/2;
            long long curr = 0;
            for (int i = 1; i < (1 << n); i++) {
                long long cnt = 0;
                long long l = 1;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        l = lcm(l, (long long)coins[j]);
                        cnt++;
                    }
                }
                if (cnt % 2 == 0) {
                    curr -= (mid/l);
                }
                else curr += (mid/l);
            }
            if (curr >= k) {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        
        return ans;
    }
};