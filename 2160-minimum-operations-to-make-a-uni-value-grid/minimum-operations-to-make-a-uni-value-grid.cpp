class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        
        int remainder = nums[0] % x;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % x != remainder) {
                return -1;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size()/2];
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i]-median)/x;
        }
        
        return ans;
    }
};