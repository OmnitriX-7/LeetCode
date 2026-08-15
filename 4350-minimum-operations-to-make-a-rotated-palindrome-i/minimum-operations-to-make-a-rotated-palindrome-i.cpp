class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        string z = s+s;

        for (int i = 0; i < n; i++) {
            int p = i;
            int x = i, y = i+n-1;
            while (x < y) {
                p += min(abs(z[x]-z[y]), 26-abs(z[x]-z[y]));
                x++, y--;
            }
            ans = min(ans, p);
        }
        return ans;
    }
};