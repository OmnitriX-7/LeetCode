class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int& curr_area){
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }
        curr_area++;
        grid[i][j] = 0;
        dfs(grid, i+1, j, curr_area);
        dfs(grid, i-1, j, curr_area);
        dfs(grid, i, j+1, curr_area);
        dfs(grid, i, j-1, curr_area);
        return curr_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1){
                    int curr_area = 0;
                    max_area = max(max_area, dfs(grid, i, j, curr_area));
                }
            }
        }
        return max_area;
    }
};