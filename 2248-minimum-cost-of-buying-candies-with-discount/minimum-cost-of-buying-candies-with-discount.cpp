class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) return cost[0];
        sort(cost.begin(), cost.end());
        long long ans = 0;
        int i = n-1;
        while (i >= 0) {
            ans += cost[i];
            if (i-1 >= 0) ans += cost[i-1];
            i -= 3;
        }
        return ans;
    }
};