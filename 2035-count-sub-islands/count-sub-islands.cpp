class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited, int i, int j, bool& isSub) {
        int m = grid1.size();
        int n = grid1[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0 || visited[i][j]) {
            return;
        }
        
        visited[i][j] = 1;

        if (grid1[i][j] == 0){
            isSub = false;
        }

        dfs(grid1, grid2, visited, i+1, j, isSub);
        dfs(grid1, grid2, visited, i-1, j, isSub);
        dfs(grid1, grid2, visited, i, j+1, isSub);
        dfs(grid1, grid2, visited, i, j-1, isSub);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt_sub = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    bool isSub = true;
                    dfs(grid1, grid2, visited, i, j, isSub);
                    if (isSub) cnt_sub++;
                }
            }
        }
        return cnt_sub;
    }
};