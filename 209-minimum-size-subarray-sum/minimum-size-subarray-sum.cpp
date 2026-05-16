class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        long long sum = 0;
        int p = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            while (sum >= target) {
                ans = min(ans, i-p+1);
                sum -= nums[p++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};