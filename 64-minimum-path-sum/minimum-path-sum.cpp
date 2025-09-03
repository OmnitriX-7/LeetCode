class Solution {
public:
    vector<vector<int>> memo;

    int minSum(vector<vector<int>> &memo, int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (x >= n || y >= m) return INT_MAX;

        if (x == n-1 && y == m-1) return grid[x][y];

        if (memo[x][y] != -1) return memo[x][y];

        memo[x][y] = grid[x][y] + min(minSum(memo,x+1,y,grid), minSum(memo,x,y+1,grid));
        return memo[x][y];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memo.assign(n,vector<int>(m, -1));
        return minSum(memo,0,0, grid);
    }
};