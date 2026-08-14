class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = 1;
        map<char, int> mp;
        int l = 0;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            while (mp[s[i]] > 2) {
                mp[s[l++]]--;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};