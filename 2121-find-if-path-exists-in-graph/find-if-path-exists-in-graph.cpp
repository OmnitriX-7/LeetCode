class Solution {
public:
    void bfs(vector<vector<int>>& AdjList, vector<bool>& visited, int source) {
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for (auto i : AdjList[curr]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    void constructAdj(vector<vector<int>>& edges, vector<vector<int>>& AdjList){
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            AdjList[edges[i][0]].push_back(edges[i][1]);
            AdjList[edges[i][1]].push_back(edges[i][0]);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> AdjList(n);
        constructAdj(edges, AdjList);
        vector<bool> visited(n,false);

        bfs(AdjList, visited, source);
        
        if (visited[destination]) return true;
        return false;
    }
};