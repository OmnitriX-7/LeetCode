class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int mn = INT_MAX;
        vector<int> idx;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') idx.push_back(i);
        }

        if (idx.size() < k) return "";

        for (int i = 0; i+k-1 < idx.size(); i++) {
            int curr = idx[i+k-1]-idx[i]+1;
            mn = min(mn, curr);
        }

        string ans;
        for (int i = 0; i+k-1 < idx.size(); i++) {
            int curr = idx[i+k-1]-idx[i]+1;
            if (curr == mn) {
                if (ans.empty()) {
                    for (int j = idx[i]; j <= idx[i+k-1]; j++) {
                        ans += s[j];
                    }
                }
                else {
                    string tmp;
                    for (int j = idx[i]; j <= idx[i+k-1]; j++) {
                        tmp += s[j];
                    }
                    if (tmp < ans) ans = tmp;
                }
            }
        }
        return ans;
    }
};