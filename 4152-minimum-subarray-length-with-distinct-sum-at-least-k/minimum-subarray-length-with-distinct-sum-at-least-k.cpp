class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int sum = 0;
        int ans = INT_MAX;
        unordered_map<int, int> freq;

        while (r < nums.size()) {
            freq[nums[r]]++;
            if (freq[nums[r]] == 1) sum += nums[r];

            while (sum >= k) {
                ans = min(ans, r - l + 1);
                if (freq[nums[l]] == 1) sum -= nums[l];
                freq[nums[l]]--;
                l++;
            }
            r++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};