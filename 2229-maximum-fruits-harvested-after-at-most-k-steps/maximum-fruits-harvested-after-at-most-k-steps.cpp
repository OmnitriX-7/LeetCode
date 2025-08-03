class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxPos = max(startPos + k, fruits.back()[0]);
        vector<int> normal(maxPos + 1, 0);

        for (int i = 0; i < n; i++){
            normal[fruits[i][0]] = fruits[i][1];
        }

        vector<int> prefixSum(maxPos+1,0);
        prefixSum[0] = normal[0];
        
        for (int i = 1; i < maxPos+1; i++) {
            prefixSum[i] = prefixSum[i-1]+normal[i];
        }

        int res = 0;
        
        for (int i = 0; i <= k; i++) {
            int left = startPos-i;
            if (left < 0) break;
            int rem = k - 2*i;
            int right = min(maxPos, startPos+rem);
            int sum = (left == 0 ? prefixSum[right] : prefixSum[right] - prefixSum[left - 1]);
            res = max(sum, res);
        }

        for (int i = 0; i <= k; i++) {
            int right = startPos+i;
            if (right > maxPos) break;
            int rem = k - 2*i;
            int left = max(0, startPos-rem);
            int sum = (left == 0 ? prefixSum[right] : prefixSum[right] - prefixSum[left - 1]);
            res = max(sum, res);
        }

        return res;
    }
};