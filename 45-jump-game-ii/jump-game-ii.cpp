class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr_end = 0, farthest = 0, jumps = 0;
        for (int i = 0; i < n-1; i++) {
            farthest = max(farthest, i+nums[i]);
            if (i == curr_end) {
                jumps++;
                curr_end = farthest;
                if (curr_end >= n-1) break;
            }
        }
        return jumps;
    }
};