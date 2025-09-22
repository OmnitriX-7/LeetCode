class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (auto i : nums){
            freq[i]++;
        }

        int mx = INT_MIN;
        for (auto i : freq) {
            mx = max(mx, i.second);
        }

        int ans = 0;
        for (auto i : freq) {
            if (i.second == mx) ans += mx;
        }
        return ans;
    }
};