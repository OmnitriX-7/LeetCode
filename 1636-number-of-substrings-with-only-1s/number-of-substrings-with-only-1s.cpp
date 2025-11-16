class Solution {
public:
    const long long m = 1e9 + 7;
    const long long inv2 = 500000004;

    int numSub(string s) {
        long long seg = 0, total = 0;

        for (char c : s) {
            if (c == '1') seg++;
            else {
                total = (total + seg * (seg + 1) % m * inv2 % m) % m;
                seg = 0;
            }
        }

        if (seg) total = (total + seg * (seg + 1) % m * inv2 % m) % m;

        return total;
    }
};
