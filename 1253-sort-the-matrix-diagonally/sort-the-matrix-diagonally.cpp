class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> min_diag;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                min_diag[i-j].push(mat[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = min_diag[i-j].top();
                min_diag[i-j].pop();
            }
        }

        return mat;
    }
};