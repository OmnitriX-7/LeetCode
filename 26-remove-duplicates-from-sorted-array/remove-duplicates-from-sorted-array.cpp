class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        int mn = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mn) {
                nums[p++] = nums[i];
                mn = nums[i];
            }
        }
        return p;
    }
};