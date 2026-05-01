class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long curr = 0;
        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += (i * nums[i]);
            total += nums[i];
        }

        long long ans = curr;
        for (int i = n-1; i >= 1; i--) {
            long long val = curr + total - (n * nums[i]);
            ans = max(ans, val);
            curr = val;
        }

        return ans;
    }
};