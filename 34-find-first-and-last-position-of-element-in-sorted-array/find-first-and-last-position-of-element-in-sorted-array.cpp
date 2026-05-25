class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        
        if (l == nums.end() || *l != target) {
            return {-1, -1};
        }
        
        auto r = upper_bound(l, nums.end(), target);
        
        return {int(l - nums.begin()), int(r - nums.begin()) - 1};
    }
};