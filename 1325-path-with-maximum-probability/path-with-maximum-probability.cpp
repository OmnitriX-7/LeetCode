class Solution {
public:
    vector<vector<vector<double>>> construct(vector<vector<int>>& edges, vector<double>& succProb, int n) {
        vector<vector<vector<double>>> res(n);
        int i = 0;

        for (auto& it : edges) {
            double first = it[0], second = it[1]; double prob = succProb[i];
            res[first].push_back({second, prob});
            res[second].push_back({first, prob});
            i++;
        }
        return res;
    }

    vector<double> dijkstra(vector<vector<vector<double>>>& AdjList, int n, double start) {
        priority_queue<vector<double>> maxh;
        maxh.push({1.0, start});

        vector<double> pro(n, 0.0);
        pro[start] = 1.0;

        while (!maxh.empty()) {
            double p = maxh.top()[0];
            double node = maxh.top()[1];
            maxh.pop();

            if (p < pro[node]) continue;

            for (auto x : AdjList[node]) {
                double to = x[0], prob = x[1];
                
                if (pro[to] < pro[node]*prob) {
                    pro[to] = pro[node]*prob;
                    maxh.push({pro[to], to});
                }
            }
        }
        return pro;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<vector<double>>> AdjList = construct(edges, succProb, n);
        vector<double> probability = dijkstra(AdjList, n, start_node);
        
        if (probability[end_node] != 0) {
            return probability[end_node];
        }

        return 0;
    }
};