class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        for (int i = 0; i < n; i++) {
            if (sum == (total-sum-nums[i])) return i;
            sum += nums[i];
        }

        return -1;
    }
};