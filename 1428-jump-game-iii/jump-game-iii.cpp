class Solution {
public:
    int dfs(vector<int>& arr, int idx, vector<int>& vis) {
        if (idx < 0 || idx >= arr.size() || vis[idx]) {
            return 0;
        }
        
        if (arr[idx] == 0) {
            return 1;
        }
        
        vis[idx] = 1;

        return dfs(arr, idx-arr[idx], vis) || dfs(arr, idx+arr[idx], vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return dfs(arr, start, vis);
    }
};