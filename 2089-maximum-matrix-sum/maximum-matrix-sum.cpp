class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long total = 0;
        int neg = 0;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                total += abs(matrix[i][j]);
                if (matrix[i][j] < 0) neg++;
                mn = min(mn, abs(matrix[i][j]));
            }
        }

        if (neg % 2 == 0) return total;
        return total - 2*mn;
    }
};