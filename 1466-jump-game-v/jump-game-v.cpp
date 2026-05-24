class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<pair<int, int>> sortedArr(n);
        
        for (int i = 0; i < n; ++i) {
            sortedArr[i] = {arr[i], i};
        }
        
        sort(sortedArr.begin(), sortedArr.end());
        
        vector<int> dp(n, 1);
        int max_total_jumps = 1;
        
        for (int k = 0; k < n; ++k) {
            int i = sortedArr[k].second;
            
            for (int j = i+1; j <= min(i+d, n-1); ++j) {
                if (arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], 1+dp[j]);
            }
            
            for (int j = i-1; j >= max(0, i-d); --j) {
                if (arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], 1+dp[j]);
            }
            
            max_total_jumps = max(max_total_jumps, dp[i]);
        }
        
        return max_total_jumps;
    }
};