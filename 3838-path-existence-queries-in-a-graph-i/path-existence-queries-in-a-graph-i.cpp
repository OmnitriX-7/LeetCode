class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> cluster(n);
        int curr = 0;
        cluster[0] = curr;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i]-nums[i-1] > maxDiff) {
                curr++;
            }
            cluster[i] = curr;
        }
        
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = (cluster[queries[i][0]] == cluster[queries[i][1]]);
        }
        
        return ans;
    }
};