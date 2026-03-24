#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long len = n * m;

        vector<int> pre(len, 1), suf(len, 1);
        vector<vector<int>> ans(n, vector<int>(m, 1));

        long long curr = 1;
        for (int i = 0; i < len; i++){
            pre[i] = curr;
            curr = (curr * grid[i/m][i%m]) % MOD;
        }
        
        curr = 1;
        for (int i = len - 1; i >= 0; i--){
            suf[i] = curr;
            curr = (curr * grid[i/m][i%m]) % MOD;
        }

        for (int i = 0; i < len; i++){
            ans[i/m][i%m] = (1LL * pre[i] * suf[i]) % MOD;
        }

        return ans;
    }
};