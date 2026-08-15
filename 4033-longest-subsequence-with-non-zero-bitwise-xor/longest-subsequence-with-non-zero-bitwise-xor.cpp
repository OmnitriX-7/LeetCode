class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());\
        if (nums[0] == nums[n-1] && nums[0] == 0) {
            return 0;
        }

        int x = 0;
        for (int i = 0; i < n; i++) {
            x ^= nums[i];
        }
        
        return x == 0 ? n-1 : n;
    }
};