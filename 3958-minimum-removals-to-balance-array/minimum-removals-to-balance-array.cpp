class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int ans = n-1;

        while (i <= j){
            while (j < n && nums[j] <= (long long)k * nums[i]){
                ans = min(ans, n - (j-i+1));
                j++;
            }
            i++;
        }
        return ans;
    }
};