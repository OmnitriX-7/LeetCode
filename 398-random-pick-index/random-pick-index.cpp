class Solution {
public:
    map<int, vector<int>> idx;
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            idx[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n = idx[target].size();
        int x = rand() % n;
        return idx[target][x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */