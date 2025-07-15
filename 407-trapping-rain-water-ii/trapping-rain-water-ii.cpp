class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int r =  heightMap.size();
        int c = heightMap[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> vis(r, vector<int> (c));

        //adding leftmost and rightmost boundaries
        for (int i = 0; i < r; i++) {      
            pq.push({heightMap[i][0], {i,0}});
            pq.push({heightMap[i][c-1], {i,c-1}});
            vis[i][0] = 1;
            vis[i][c-1] = 1;
        }

        //addding uppermost and lowermost boundaries
        for (int i = 0; i < c; i++) {
            pq.push({heightMap[0][i], {0,i}});
            pq.push({heightMap[r-1][i], {r-1,i}});
            vis[0][i] = 1;
            vis[r-1][i] = 1;
        }

        //left, right, up, down
        vector<int> dr = {0,0,-1,1};
        vector<int> dc = {-1,1,0,0};

        int ans = 0;

        while (!pq.empty()) {
            int curr_height = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr>=0 && nr<r && nc>=0 && nc<c && !vis[nr][nc]) {
                    ans += max(0, curr_height-heightMap[nr][nc]);
                    pq.push({max(curr_height,heightMap[nr][nc]),{nr,nc}});
                    vis[nr][nc] = 1;
                }
            }
        }

        return ans;
    }
};