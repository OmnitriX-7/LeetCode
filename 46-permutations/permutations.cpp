class Solution {
public:

    void generate(int mask, int n, vector<int>& curr, vector<vector<int>>& res, vector<int> nums) {
        if (mask == (1 << n) - 1) { 
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {  
                curr.push_back(nums[i]);
                generate(mask | (1 << i), n, curr, res, nums);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        generate(0, n, curr, res, nums);
        return res;
    }
};