class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int p = 0;
        int i = 1;
        while (p < nums.size()) {
            if (nums[p] & 1) {
                res[i] = nums[p];
                i+=2;
            }
            p++;
        }

        p = 0;
        i = 0;
        while (p < nums.size()) {
            if ((nums[p] & 1) == 0) {
                res[i] = nums[p];
                i+=2;
            }
            p++;
        }
        return res;
    }
};