class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({arr[i], i});
        }
        sort(vp.begin(), vp.end());
        vector<int> ans(n);

        int j = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) ans[vp[i].second] = j;
            else if (vp[i].first > vp[i-1].first) {
                ++j;
                ans[vp[i].second] = j;
            }
            else ans[vp[i].second] = j;
        }
        return ans;
    }
};