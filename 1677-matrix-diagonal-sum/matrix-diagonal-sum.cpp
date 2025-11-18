class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += mat[i][i];
        }
        for (int i = n-1, j = 0; i >= 0, j < m; i--, j++){
            sum += mat[i][j];
        }
        
        if (n % 2 == 1){
            sum -= mat[n/2][n/2];
        }

        return sum;
    }
};