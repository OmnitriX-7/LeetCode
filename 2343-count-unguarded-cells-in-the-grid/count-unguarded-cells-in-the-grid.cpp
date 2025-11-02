class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> combined(m, vector<int>(n,0));
        for (auto i : guards){
            combined[i[0]][i[1]] = 2;
        }
        for (auto i : walls){
            combined[i[0]][i[1]] = 2;
        }

        vector<vector<int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for (auto i : guards) {
            int row = i[0];
            int col = i[1];
            for (int j = 0; j < 4; j++) {
                int nr = row + d[j][0];
                int nc = col + d[j][1];
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && combined[nr][nc] != 2) {
                    combined[nr][nc] = 1;
                    nr += d[j][0];
                    nc += d[j][1];
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (combined[i][j] == 0){
                    count++;
                } 
            }
        }
        return count;
    }
};