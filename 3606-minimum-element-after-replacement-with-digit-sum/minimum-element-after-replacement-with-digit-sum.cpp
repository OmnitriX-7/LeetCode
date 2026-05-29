class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            int cur = 0;
            while (tmp > 0) {
                cur += tmp % 10;
                tmp /= 10;
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};