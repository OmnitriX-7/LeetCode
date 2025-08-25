class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        int m = s.size();
        string ans;
        unordered_map<char, int> freq;
        for (int i=0; i < m; i++) {
            freq[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            while (freq[order[i]]--) {
                ans += order[i];
            }
        }
        for (int i = 0; i < m; i++) {
            if (freq[s[i]] > 0) {
                while (freq[s[i]]--) {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};