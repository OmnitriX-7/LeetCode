class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = n/2;
        int med_ele = nums[med];
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += abs(med_ele - nums[i]);
        }
        return ans;
    }
};