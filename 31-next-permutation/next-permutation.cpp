class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        for (i; i > 0; i--) {
            if (nums[i] > nums[i-1]){
                break;
            }
        }

        if (i > 0){
            for (int j = nums.size()-1; j >= i; j--) {
                if (nums[j] > nums[i-1]){
                    swap(nums[j], nums[i-1]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i, nums.end());
    }
};