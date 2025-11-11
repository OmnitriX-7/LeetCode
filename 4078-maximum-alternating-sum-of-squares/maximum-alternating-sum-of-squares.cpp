class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (auto& i : nums) {
            if (i < 0) i *= -1;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++){
            if (i < n/2) ans -= (long long)(nums[i]*nums[i]);
            else ans += (long long)(nums[i]*nums[i]);
        }
           
        return ans;
    }
};