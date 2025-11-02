class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0;
        long long curr = 1;
        int res = 0;
        while (curr <= n) {
            if (i < nums.size() && nums[i] <= curr){
                curr += nums[i];
                i++;
            }
            else {
                curr += curr;
                res++;
            }
        }

        return res;
    }
};