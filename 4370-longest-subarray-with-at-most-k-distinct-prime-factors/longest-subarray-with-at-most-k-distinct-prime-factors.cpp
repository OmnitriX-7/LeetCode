class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int l = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 2; j*j <= x; j++) {
                if (x % j == 0) {
                    mp[j]++;
                    while (x % j == 0) x /= j;
                }
            }
            if (x > 1) mp[x]++;
            
            while (mp.size() > k && l <= i) {
                x = nums[l];
                for (int j = 2; j*j <= x; j++) {
                    if (x % j == 0) {
                        mp[j]--;
                        if (mp[j] == 0) mp.erase(j);
                        while (x % j == 0) x /= j;
                    }
                }
                if (x > 1) {
                    mp[x]--;
                    if (mp[x] == 0) mp.erase(x);
                }
                l++;
            }

            ans = max(ans, i-l+1);
        }

        return ans;
    }
};