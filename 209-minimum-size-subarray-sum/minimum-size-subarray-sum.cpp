class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for (int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        int i = 0, j = 1;
        int ans = INT_MAX;

        while (j < n+1) {
            if (prefix[j] - prefix[i] >= target){
                ans = min(ans, j-i);
                i++;
            }
            else {
                j++;
            }
        }

        if (ans == INT_MAX) return 0;
        return ans;
    }
};