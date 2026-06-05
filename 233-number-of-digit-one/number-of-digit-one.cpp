class Solution {
public:
    long long dp[20][2][20];

    long long solve(string& s, int idx, int flag, long long cnt) {
        if (idx == s.size()) return cnt;
        if (dp[idx][flag][cnt] != -1) return dp[idx][flag][cnt];

        long long ans = 0;

        int limit = (flag == 1 ? s[idx]-'0' : 9);
        for (int i = 0; i <= limit; i++) {
            long long curr = cnt + (i == 1 ? 1 : 0);
            ans += solve(s, idx+1, flag && (i == limit), curr);
        }

        return dp[idx][flag][cnt] = ans;
    }

    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        string r = to_string(n);
        return solve(r, 0, 1, 0);
    }
};