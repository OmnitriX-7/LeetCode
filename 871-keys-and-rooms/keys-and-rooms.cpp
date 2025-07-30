class Solution {
public:
    void bfs(vector<vector<int>>& rooms, vector<bool>& visited, int i) {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (auto i : rooms[curr]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        
        bfs(rooms,visited,0);

        for (auto i : visited){
            if (!i) return false;
        }
        return true;
    }
};