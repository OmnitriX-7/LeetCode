class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++){
            if (nums[i] <= nums[i-1]){
                int d = nums[i-1] - nums[i];
                nums[i] += d + 1;
                cnt += d + 1;
            }
        }
        return cnt;
    }
};