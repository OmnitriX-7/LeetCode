class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0;
        for (int i = 0; i < k; i++) {
            avg += nums[i];
        }
        double mx = avg;
        for (int i = k; i < n; i++) {
            avg += nums[i] - nums[i-k];
            if (avg > mx) mx = avg;
        }
        return mx/k;
    }
};