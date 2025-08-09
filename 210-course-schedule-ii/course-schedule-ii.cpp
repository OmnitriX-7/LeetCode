class Solution {
public:

    vector<vector<int>> constructAdj(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> res(n);
        for (auto& i : prerequisites){
            res[i[1]].push_back(i[0]);
        }
        return res;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjList = constructAdj(n, prerequisites);

        vector<int> indegree(n,0);
        for (int i = 0; i < n; i++) {
            for (auto& x : adjList[i]){
                indegree[x]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (auto i : adjList[curr]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if (order.size() == n) return order;
        return {};
    }
};