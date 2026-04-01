class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = count(bank[0].begin(), bank[0].end(), '1');
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int c1 = count(bank[i].begin(), bank[i].end(), '1');
            if (c1) {
                ans += (c1 * prev);
                prev = c1;
            }
        }
        return ans;
    }
};