class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        int mn_ans = nums[0];
        int mx = nums[0];
        int mx_ans = nums[0];
        int total = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 1; i < n; i++) {
            mn = min(nums[i], mn+nums[i]);
            mn_ans = min(mn_ans, mn);
            mx = max(nums[i], mx+nums[i]);
            mx_ans = max(mx_ans, mx);
        }

        if (mx_ans < 0) return mx_ans;

        return max(mx_ans, total-mn_ans);
    }
};