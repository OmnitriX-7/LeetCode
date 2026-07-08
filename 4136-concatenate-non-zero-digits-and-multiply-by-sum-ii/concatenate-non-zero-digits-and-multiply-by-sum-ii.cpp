class Solution {
public:
    int MOD = 1000000007;

    long long Power(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res*base) % MOD;
            }
            base = (base*base) % MOD;
            exp /= 2;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> pre(n+1, 0);
        vector<long long> digit(n+1, 0);
        vector<int> len(n+1, 0);
        
        for (int i = 0; i < n; i++) {
            int d = s[i]-'0';
            
            pre[i+1] = pre[i]+d;
            
            if (d) {
                digit[i+1] = (digit[i]*10 + d) % MOD;
                len[i+1] = len[i]+1;
            }
            else {
                digit[i+1] = digit[i];
                len[i+1] = len[i];
            }
        }
        
        vector<int> res;
        
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            
            long long powerOf10 = Power(10, len[r]-len[l]);
            
            long long sub = (digit[l]*powerOf10) % MOD;
            long long x = (digit[r]-sub + MOD) % MOD;
            long long sumOfDigits = pre[r]-pre[l];
            
            res.push_back((x*sumOfDigits) % MOD);
        }
        
        return res;
    }
};