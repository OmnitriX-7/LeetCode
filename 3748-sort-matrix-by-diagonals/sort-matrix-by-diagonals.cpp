class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, priority_queue<int>> bottom_left;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> top_right;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i >= j) {
                    bottom_left[i - j].push(grid[i][j]);
                } else {
                    top_right[i - j].push(grid[i][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i >= j) {
                    grid[i][j] = bottom_left[i - j].top();
                    bottom_left[i - j].pop();
                } else {
                    grid[i][j] = top_right[i - j].top();
                    top_right[i - j].pop();
                }
            }
        }

        return grid;
    }
};