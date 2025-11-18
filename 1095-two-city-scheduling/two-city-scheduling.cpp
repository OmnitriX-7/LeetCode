class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> extra;
        int minCost = 0;
        for (int i = 0; i < n; i++){
            minCost += costs[i][0];
            extra.push_back(costs[i][1]-costs[i][0]);
        }
        sort(extra.begin(), extra.end());
        for (int i = 0; i < n/2; i++){
            minCost += extra[i];
        }
        return minCost;
    }
};