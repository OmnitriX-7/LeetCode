class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_dp(n+1, 0), suf_dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (nums[i-1] == 1) pre_dp[i] = 1 + pre_dp[i-1];
        }
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] == 1) suf_dp[i] = 1 + suf_dp[i+1];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre_dp[i] + suf_dp[i+1]);
        }
        return ans;
    }
};