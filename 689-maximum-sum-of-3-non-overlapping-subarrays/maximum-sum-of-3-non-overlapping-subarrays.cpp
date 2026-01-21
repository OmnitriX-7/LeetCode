class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sums(n - k + 1);
        long long currentSum = 0;
        
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }
        sums[0] = currentSum;
        for (int i = k; i < n; i++) {
            currentSum += nums[i] - nums[i - k];
            sums[i - k + 1] = currentSum;
        }

        vector<int> left(sums.size());
        int best = 0;
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] > sums[best]) {
                best = i;
            }
            left[i] = best;
        }

        vector<int> right(sums.size());
        best = sums.size() - 1;
        for (int i = sums.size() - 1; i >= 0; i--) {
            if (sums[i] >= sums[best]) {
                best = i;
            }
            right[i] = best;
        }

        vector<int> ans = {-1, -1, -1};
        long long maxSum = 0;

        for (int i = k; i < sums.size() - k; i++) {
            int l = left[i - k];
            int r = right[i + k];
            long long total = sums[l] + sums[i] + sums[r];
            if (ans[0] == -1 || total > maxSum) {
                maxSum = total;
                ans = {l, i, r};
            }
        }
        
        return ans;
    }
};