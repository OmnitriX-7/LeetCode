class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i])-1] > 0) nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            else {
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
};