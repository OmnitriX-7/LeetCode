class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> visited(v,0);
        vector<int> color(v,-1);
        queue<int> q;

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                q.push(i);
            }
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (auto& i : graph[curr]) {
                    if (color[i] == -1) {
                        color[i] = 1-color[curr];
                        q.push(i);
                    }
                    else if (color[i] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};