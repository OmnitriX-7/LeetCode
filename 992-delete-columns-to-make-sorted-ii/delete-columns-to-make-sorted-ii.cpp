class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<bool> sorted(n, false);
        int ans = 0;

        for (int col = 0; col < m; col++) {
            bool bad = false;

            for (int row = 1; row < n; row++) {
                if (!sorted[row] && strs[row][col] < strs[row-1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ans++;
                continue;
            }

            for (int row = 1; row < n; row++) {
                if (!sorted[row] && strs[row][col] > strs[row-1][col]) {
                    sorted[row] = true;
                }
            }
        }
        return ans;
    }
};
