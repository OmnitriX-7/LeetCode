class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        int c = 0;
        int mn = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mn) {
                c = 1;
                nums[p++] = nums[i];
                mn = nums[i];
            }
            else if (nums[i] == mn) {
                if (c == 1) {
                    c = 2;
                    nums[p++] = nums[i];
                }
            }
        }
        return p;
    }
};