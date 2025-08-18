class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<long long>>> construct(vector<vector<int>>& roads, int n) {
        vector<vector<vector<long long>>> res(n);
        for (auto& it : roads) {
            res[it[0]].push_back({it[1], it[2]});
            res[it[1]].push_back({it[0], it[2]});
        }
        return res;
    }
    
    vector<long long> dijkstra(vector<vector<vector<long long>>>& AdjList, int n) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minh;
        minh.push({0, 0});

        vector<long long> time(n, LLONG_MAX);
        time[0] = 0;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        while (!minh.empty()) {
            long long curtime = minh.top()[0];
            int node = minh.top()[1];
            minh.pop();

            if (curtime > time[node]) continue;

            for (auto& x : AdjList[node]) {
                long long dst = x[0], t = x[1];
                if (time[dst] > time[node]+t) {
                    time[dst] = time[node]+t;
                    ways[dst] = ways[node];
                    minh.push({time[dst], dst});
                }
                else if (time[dst] == time[node]+t) {
                    ways[dst] = (ways[dst] + ways[node]) % MOD;
                }
            }
        }
        return ways;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<long long>>> AdjList = construct(roads, n);
        vector<long long> ans = dijkstra(AdjList, n);
        return ans[n-1] % MOD;
    }
};