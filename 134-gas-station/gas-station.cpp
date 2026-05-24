class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) diff[i] = gas[i]-cost[i];
        for (int i = 0; i < n; i++) diff.push_back(diff[i]);

        int l = 0;
        long long sum = 0;
        for (int i = 0; i < 2*n; i++) {
            sum += diff[i];
            if (sum < 0) {
                l = i+1;
                sum = 0;
            }
            if (i-l+1 == n) return l;
        }
        return -1;
    }
};