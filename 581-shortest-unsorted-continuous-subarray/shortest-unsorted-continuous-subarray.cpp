class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums = nums;
        sort(new_nums.begin(), new_nums.end());
        int idx = -1;
        for (int i = 0; i < n-1; i++){
            if (nums[i] != new_nums[i]){
                idx = i;
                break;
            }
        }
        if (idx != -1){
            for (int j = n-1; j > 0; j--){
                if (nums[j] != new_nums[j]){
                    return j-idx+1;
                }
            }
        }
        return 0;
    }
};