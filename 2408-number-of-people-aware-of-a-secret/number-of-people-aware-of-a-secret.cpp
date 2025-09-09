class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        dp[1] = 1;
        long long people = 0;
        long long MOD = 1e9+7;
        for (int i = 2; i <= n; i++) {
            if (i - delay > 0) {
                people = (people + dp[i-delay] + MOD) % MOD;
            }
            if (i - forget > 0) {
                people = (people - dp[i-forget] + MOD) % MOD;
            }
            dp[i] = people;
        }

        long long ans = 0;
        for (int i = n-forget+1; i <= n; i++){
            ans += (dp[i] % MOD);
        }
        ans %= MOD;
        return (int)ans;
    }
};