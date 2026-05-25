class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int zeroes = 0;
        int ones = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) ones++;
            else zeroes++;
            while (zeroes > k && l <= i) {
                if (nums[l] == 0) zeroes--;
                else ones--;
                l++;
            }
            ans = max(ans, ones+zeroes);
        }
        return ans;
    }
};