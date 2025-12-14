class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n+1, 0);
        vector<vector<int>> adjMat(n+1, vector<int>(n+1, 0));

        for (auto& e : edges){
            degree[e[0]]++;
            degree[e[1]]++;
            adjMat[e[0]][e[1]] = 1;
            adjMat[e[1]][e[0]] = 1;
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++){
            for (int j = i+1; j <= n; j++){
                if (adjMat[i][j]){
                    for (int k = j+1; k <= n; k++){
                        if (adjMat[i][k] && adjMat[j][k]){
                            ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                        }
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;    
    }
};