class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        int sz = 0;

        for (int x : nums) {
            if (x >= 0) sz++;
        }

        if (sz == 0) return nums;
        k %= sz;

        vector<pair<int, int>> pos;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                int target_pos = (idx - k + sz) % sz;
                pos.push_back({nums[i], target_pos});
                idx++;
            }
        }

        sort(pos.begin(), pos.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                nums[i] = pos[j].first;
                j++;
            }
        }
        return nums;
    }
};