class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int z = count(s.begin(), s.end(), '0');
        z = min(z, n-z);
        int ones = count(s.begin(), s.end(), '1');
        if (ones <= 1) z = 0;
        else if (ones >= 2) z = min(z, ones-1);
        int x = 0;
        if (s[0] == '0') x++;
        if (s[n-1] == '0') x++;
        for (int i = 1; i < n-1; i++) {
            if (s[i] == '1') x++;
        }
        return min(z,x);
    }
};