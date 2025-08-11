class Solution {
public:
    long calc_inv(int lower, int power, int mod){
        long long res = 1;
        long base = lower%mod;
        while (power > 0){
            if (power & 1){
                res = (res*base) % mod;
            }
            power /= 2;
            base = (base*base) % mod;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> res;
        while(n > 0){
            int pos = __builtin_ctz(n);
            res.push_back(1<<pos);
            n &= (n-1);
        }

        vector<long long> pre_product(res.size()+1,1);
        for (int i=1; i<res.size()+1; i++){
            pre_product[i] = ((res[i-1] % MOD)*(pre_product[i-1] % MOD)) % MOD;
        }
        
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++){
            int upper = pre_product[queries[i][1]+1];
            int lower = pre_product[queries[i][0]];
            long long mod_inv = calc_inv(lower, MOD-2, MOD);
            ans.push_back((upper*mod_inv) % MOD);
        }
        return ans;
    }
};