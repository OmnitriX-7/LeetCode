class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> v(128,0);
        int ans = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            v[s[i]]++;
            while (v[s[i]] > 1) {
                v[s[prev++]]--;
            }
            ans = max(ans, i-prev+1);
        }
        return ans;
    }
};