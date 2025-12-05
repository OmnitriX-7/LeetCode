class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0;
        int ans = 0;
        for (int i = 0; i < n-1; i++){
            curr += nums[i];
            if (abs(curr - (total-curr)) % 2 == 0) ans++;
        }
        return ans;
    }
};