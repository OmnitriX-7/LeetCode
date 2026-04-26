class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum = nums[0];
        long long mx = *max_element(nums.begin(), nums.end());
        sum -= mx;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) sum += nums[i];
            else sum -= nums[i];
        }

        if (sum > 0) return 0;
        else if (sum < 0) return 1;
        return -1;
    }
};