class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        
        if (s == sorted_s) return 0;
        if (n == 2) return -1;

        int mn = s[0], mx = s[0];
        for (char c : s) {
            mn = min(mn, (int)c);
            mx = max(mx, (int)c);
        }

        if (s[0] == mx && s[n - 1] == mn) {
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == mn || s[i] == mx) return 2;
            }
            return 3;
        }

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        return 2;
    }
};