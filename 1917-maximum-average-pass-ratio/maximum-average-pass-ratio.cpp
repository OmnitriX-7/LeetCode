class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> maxh;
        for (double i = 0; i < classes.size(); i++){
            double a = classes[i][0];
            double b = classes[i][1];
            maxh.push({(a+1)/(b+1) - (a/b), i});
        }

        while (extraStudents--) {
            double idx = maxh.top()[1];
            maxh.pop();
            ++classes[idx][0]; ++classes[idx][1];
            double a = classes[idx][0];
            double b = classes[idx][1];
            maxh.push({(a+1)/(b+1) - (a/b), idx});
        }

        double final = 0.0;
        for (auto i : classes){
            final += (double)i[0]/i[1];
        }
        return final/classes.size();
    }
};