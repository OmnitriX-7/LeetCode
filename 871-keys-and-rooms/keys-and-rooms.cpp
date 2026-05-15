class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);

        while (!q.empty()){
            int top = q.front();
            q.pop();
            for (auto& i : rooms[top]) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return 0;
        }
        return 1;
    }
};