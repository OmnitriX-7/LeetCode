class Solution {
public:
    void generate(vector<int>& nums, vector<int>& curr, int mask, set<vector<int>>& s){
        int n = nums.size();
        if (mask == (1 << n)-1) {
            s.insert(curr);
            return;
        }
        for (int i = 0; i < n; i++){
            if (!(mask & (1 << i))){
                curr.push_back(nums[i]);
                generate(nums, curr, mask | (1 << i), s);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {    
        set<vector<int>> s;
        vector<int> curr;
        generate(nums, curr, 0, s);
        vector<vector<int>> res;
        for (auto i : s){
            res.push_back(i);
        }
        return res;
    }
};