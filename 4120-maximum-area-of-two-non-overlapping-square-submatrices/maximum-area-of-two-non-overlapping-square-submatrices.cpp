class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pre(n+1, vector<int>(m+1,0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = mat[i-1][j-1]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
            }
        }

        for (int i = min(n, m); i >= 1; i--) {
            int min_x = n, max_x = -1;
            int min_y = m, max_y = -1;
            
            for (int x = 0; x <= n - i; x++) {
                for (int y = 0; y <= m - i; y++) {
                    if (pre[x+i][y+i]-pre[x+i][y]-pre[x][y+i]+pre[x][y] == i*i) {
                        if (x < min_x) min_x = x;
                        if (x > max_x) max_x = x;
                        if (y < min_y) min_y = y;
                        if (y > max_y) max_y = y;
                    }
                }
            }
            
            if (max_x != -1 && (min_x + i <= max_x || min_y + i <= max_y)) {
                return i * i;
            }
        }

        return 0;
    }
};