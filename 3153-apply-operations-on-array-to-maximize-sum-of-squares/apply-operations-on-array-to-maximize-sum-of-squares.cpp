class Solution {
public:
    const int MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(31,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                if ((nums[i] >> j) & 1) freq[j]++;
            }
        }

        long long ans = 0;
        vector<long long> val(n, 0LL);
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < freq[i]; j++) {
                val[j] += (1LL << i);
            }
        }

        for (int i = 0; i < k; i++) {
            ans = (ans + (val[i]*val[i]) % MOD) % MOD;
        }

        return ans;
    }
};