class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = abs(left-(total-left-nums[i]));
            left += nums[i];
        }
        return ans;
    }
};