class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (nums[i] != 0) {
                i++;
                continue;
            }
            if (j <= i || nums[j] == 0) {
                j++;
                continue;
            }
            swap(nums[i], nums[j]);
            i++, j++;
        }
    }
};