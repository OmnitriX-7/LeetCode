class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        for (auto& i : nums) {
            if (i < 0) i *= -1;
        }
        sort(nums.begin(), nums.end());
        long long ans = (long long)nums[n-1] * (long long)nums[n-2] * (long long)1e5;
        return ans;
    }
};