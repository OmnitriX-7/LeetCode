class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            int target = -nums[i];
            int l = i+1;
            int r = n-1;
            while (l < r) {
                int sum = nums[l]+nums[r];
                if (sum == target) {
                    s.insert({nums[i],nums[l],nums[r]});
                    l++, r--;
                }
                else if (sum < target) l++;
                else r--;
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};