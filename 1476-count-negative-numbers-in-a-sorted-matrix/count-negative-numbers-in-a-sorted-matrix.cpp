class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i = grid.size()-1;
        int j = 0;
        int c = 0;

        while (i >= 0 && j < grid[0].size()){
            if (grid[i][j] < 0){
                c += grid[0].size()-j;
                i--;
            }
            else j++;
        }

        return c;
    }
};