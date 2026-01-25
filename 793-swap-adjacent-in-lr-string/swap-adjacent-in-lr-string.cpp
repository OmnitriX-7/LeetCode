class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        map<char, int> mp1, mp2;
        for (auto i : start) mp1[i]++;
        for (auto i : result) mp2[i]++;

        if (mp1['R'] != mp2['R'] || mp1['L'] != mp2['L']) return false;

        int p = 0, q = 0;

        while (p < n && q < n){
            while (p < n && start[p] == 'X') p++;
            while (q < n && result[q] == 'X') q++;

            if (start[p] != result[q]) return false;
            if (start[p] == 'R' && p > q) return false;
            if (start[p] == 'L' && p < q) return false;

            p++, q++;
        }

        return true;
    }
};