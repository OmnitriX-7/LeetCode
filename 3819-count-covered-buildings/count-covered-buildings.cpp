class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end(),
             [](auto &a, auto &b){ return a[0] < b[0]; });

        map<int, vector<int>> x_cors, y_cors;

        for (auto &b : buildings) {
            x_cors[b[1]].push_back(b[0]);
            y_cors[b[0]].push_back(b[1]);
        }

        for (auto &p : x_cors) sort(p.second.begin(), p.second.end());
        for (auto &p : y_cors) sort(p.second.begin(), p.second.end());

        set<pair<int,int>> middle_x;

        for (auto &p : x_cors) {
            auto &v = p.second;
            for (int i = 1; i + 1 < v.size(); i++) {
                middle_x.insert({v[i], p.first});
            }
        }

        int c = 0;

        for (auto &p : y_cors) {
            auto &v = p.second;
            for (int i = 1; i + 1 < v.size(); i++) {
                if (middle_x.count({p.first, v[i]})) c++;
            }
        }

        return c;
    }
};
