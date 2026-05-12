class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            return a[1]-a[0] > b[1]-b[0];
        });
        int sum = 0, mx = tasks[0][1];
        for (int i = 0; i < n; i++) {
            sum += tasks[i][0];
            mx = max(mx, tasks[i][1]);
        }
        int curr = max(sum, mx);
        int base = curr;
        int ex = 0;
        for (int i = 0; i < n; i++) {
            if (curr >= tasks[i][1]) {
                curr -= tasks[i][0];
            }
            else {
                ex += abs(tasks[i][1]-curr);
                curr = tasks[i][1]-tasks[i][0];
            }
        }
        return base + ex;
    }
};