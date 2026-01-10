class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.push_back({0,0});
        vector<vector<int>> dv = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for(int k = 0; k < 4; k++) {
                int nx = x + dv[k][0];
                int ny = y + dv[k][1];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int cost = (grid[x][y] == k+1) ? 0 : 1;

                    if(dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;
                        if(cost == 0) dq.push_front({nx, ny});
                        else dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};