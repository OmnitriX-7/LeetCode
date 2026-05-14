class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) >= n) return 0;
            if (abs(nums[i]) == n-1) {
                c++;
                if (c > 2) return 0;
            }
            else {
                if (nums[abs(nums[i])-1] > 0) {
                    nums[abs(nums[i])-1] *= -1;
                }
                else return 0;
            }
        }
        return c == 2;
    }
};