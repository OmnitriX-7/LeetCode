class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int last_p = 0, last_m = 0, last_g = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < garbage[i].size(); j++){
                if (garbage[i][j] == 'P') last_p = i;
                else if (garbage[i][j] == 'M') last_m = i;
                else if (garbage[i][j] == 'G') last_g = i;
            }
            ans += garbage[i].size();
        }
        vector<int> pre(travel.size()+1, 0);
        for (int i = 1; i <= travel.size(); i++) pre[i] = pre[i-1] + travel[i-1];

        ans += pre[last_p];
        ans += pre[last_g];
        ans += pre[last_m];
        return ans;
    }
};