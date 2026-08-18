class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        for (auto& i : nums) mp[i]++;

        if (k == n) return *max_element(nums.begin(), nums.end());

        if (k == 1) {
            int mx = -1;
            for (auto& i : mp) {
                if (i.second == 1) mx = max(mx, i.first);
            }
            return mx;
        }

        if (mp[nums[0]] == 1 && mp[nums[n-1]] == 1) return max(nums[0], nums[n-1]);
        else if (mp[nums[0]] == 1) return nums[0];
        else if (mp[nums[n-1]] == 1) return nums[n-1];
        else return -1;
    }
};