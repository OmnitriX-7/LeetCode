class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < reservedSeats.size(); i++) {
            mp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        
        int x = mp.size();
        int ans = 2*n;

        for (auto& i : mp) {
            unordered_set<int> st = i.second;
            int l = 0, r = 0;
            if (st.count(2) || st.count(3) || st.count(4) || st.count(5)) {
                ans--; l = 1;
            }
            if (st.count(6) || st.count(7) || st.count(8) || st.count(9)) {
                ans--; r = 1;
            }
            if (!(st.count(4) || st.count(5) || st.count(6) || st.count(7)) && (l && r)) ans++;
        }
        return ans;
    }
};