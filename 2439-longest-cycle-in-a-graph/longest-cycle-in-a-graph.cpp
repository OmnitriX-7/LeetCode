class Solution {
public:
    int ans = -1;
    int timeCounter = 1;

    void dfs(int node, vector<int>& edges, vector<int>& visited, vector<int>& enterTime) {
        if (node == -1) return;

        if (visited[node] == 1) {
            ans = max(ans, timeCounter - enterTime[node]);
            return;
        }
        if (visited[node] == 2) return; 

        visited[node] = 1; 
        enterTime[node] = timeCounter++;

        dfs(edges[node], edges, visited, enterTime);

        visited[node] = 2;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0), enterTime(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, edges, visited, enterTime);
            }
        }
        return ans;
    }
};
