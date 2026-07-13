class Solution {
public:
    void generate(vector<int>& nums) {
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            int lastDigit = nums[i]%10;
            if (lastDigit < 9) {
                nums.push_back(nums[i]*10 + lastDigit+1);
            }
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;
        generate(nums);
        vector<int> res;

        for (auto& x : nums)
            if (x >= low && x <= high)
                res.push_back(x);

        return res;
    }
};