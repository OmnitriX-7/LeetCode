class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        if (x2 == x1) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != x1) return false;
            }
            return true;
        }

        double slope = (double)(y2 - y1) / (x2 - x1);

        for (int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            double s = (double)(y - y1) / (x - x1);
            if (fabs(s - slope) > 1e-9) return false; 
        }
        return true;
    }
};