class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph, 0, path, ans);
        return ans;
    }

private:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& ans) {
        path.push_back(node);
        
        if (node == graph.size()-1) {
            ans.push_back(path);
        } 
        else {
            for (auto& v : graph[node]) {
                dfs(graph, v, path, ans);
            }
        }
        
        path.pop_back();
    }
};