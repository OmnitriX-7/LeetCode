class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        long long ans = 0;
        long long p = 1;
        int l = 0;

        for (int r = 0; r < n; r++){
            p *= nums[r];

            while (p >= k) p /= nums[l++];

            ans += r - l + 1;
        }
        return ans;
    }
};