class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start;
        for (auto& i : board){
            for (auto& j : i) start += to_string(j);
        }
        if (start == target) return 0;

        set<string> visited;
        visited.insert(start);

        queue<string> q;
        q.push(start);

        vector<vector<int>> neighbours = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        int moves = 0;

        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                string curr = q.front();
                q.pop();
                
                if (curr == target) return moves;

                int idx = curr.find('0');

                for (auto& i : neighbours[idx]){
                    string next_string = curr;
                    swap(next_string[idx], next_string[i]);
                    if (!visited.count(next_string)){
                        visited.insert(next_string);
                        q.push(next_string);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};