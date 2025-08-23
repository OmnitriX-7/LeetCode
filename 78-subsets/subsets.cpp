class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    tmp.push_back(nums[i]);
                }
            }
            v.push_back(tmp);
        }
        return v;
    }
};