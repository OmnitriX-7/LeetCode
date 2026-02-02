class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++){
            set<int> s;
            for (int i = 0; i < n; i++){
                if ((mask >> i) & 1){
                    s.insert(i);
                }
            }
            vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i == j) dist[i][j] = 0;
                }
            }
            for (auto& e : roads){
                if (!s.count(e[0]) && !s.count(e[1])) {
                    dist[e[0]][e[1]] = min(dist[e[0]][e[1]], e[2]);
                    dist[e[1]][e[0]] = min(dist[e[1]][e[0]], e[2]);
                }
            }
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dist[j][i] != INT_MAX){
                        for (int k = 0; k < n; k++){
                            if (dist[i][k] != INT_MAX){
                                dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
                            }
                        }
                    }
                }
            }
            int pos = 1;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (!s.count(i) && !s.count(j)){
                        if (dist[i][j] > maxDistance){
                            pos = 0;
                            break;
                        }
                    }
                }
            }
            if (pos) ans++;
        }
        return ans;
    }
};