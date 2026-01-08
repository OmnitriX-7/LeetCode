class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long curr = 0;
        long long target = total - x;
        int l = 0;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++){
            curr += nums[i];
            while (curr > target && l <= i){
                curr -= nums[l];
                l++;
            }
            if (curr == target){
                ans = max(ans, i-l+1);
            }
        }
        return ans == INT_MIN ? -1 : n-ans;
    }
};