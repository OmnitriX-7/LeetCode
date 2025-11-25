class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++){
            set<int> odd;
            set<int> even;
            for (int j = i; j < n; j++){
                if (nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if (odd.size() == even.size()) ans = max(ans, j-i+1);
            }
        }
        if (ans == INT_MIN) return 0;
        return ans;
    }
};