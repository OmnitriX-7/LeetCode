class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, lose;

        for (auto &i : matches) {
            win[i[0]]++;
            lose[i[1]]++;
        }

        vector<vector<int>> ans(2);

        for (auto &i : win) {
            if (lose.count(i.first) == 0)
                ans[0].push_back(i.first);
            else if (lose[i.first] == 1)
                ans[1].push_back(i.first);
        }

        for (auto &i : lose) {
            if (win.count(i.first) == 0 && i.second == 1)
                ans[1].push_back(i.first);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};
