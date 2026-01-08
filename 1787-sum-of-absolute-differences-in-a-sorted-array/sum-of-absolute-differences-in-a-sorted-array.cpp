class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1, 0);
        for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + nums[i-1];

        long long total = pre[n];
        vector<int> ans;

        for (int i = 0; i < n; i++){
            int upper = (total-pre[i+1]) - ((n-i-1)*nums[i]);
            int lower = i*nums[i] - pre[i];
            ans.push_back(upper + lower);
        }

        return ans;
    }
};