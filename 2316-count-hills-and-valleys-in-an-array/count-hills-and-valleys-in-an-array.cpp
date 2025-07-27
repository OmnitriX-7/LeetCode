class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] != nums[i+1]) {
                res.push_back(nums[i]);
            }
        }
        res.push_back(nums[n-1]);

        int cnt = 0;

        for (int i = 1; i < res.size()-1; i++) {
            if ((res[i] < res[i-1]) && (res[i] < res[i+1])) cnt++;
            else if ((res[i] > res[i-1]) && (res[i] > res[i+1])) cnt++;
        }
        return cnt;
    }
};