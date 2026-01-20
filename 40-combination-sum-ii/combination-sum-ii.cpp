class Solution {
public:
    void solve(int idx, vector<vector<int>>& ans, vector<int>& temp, vector<int>& candidates, int target){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            if (target < candidates[i]) break;
            temp.push_back(candidates[i]);
            solve(i+1, ans, temp, candidates, target-candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, ans, temp, candidates, target);
        return ans;
    }
};