class Solution {
public:
    int res(vector<int>& ls,vector<int>& ld,vector<int>& ws,vector<int>& wd) {
        int mn = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            mn = min(mn, ls[i]+ld[i]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < ws.size(); i++) {
            ans = min(ans,max(mn, ws[i]) + wd[i]);
        }
        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(res(landStartTime,landDuration,waterStartTime,waterDuration), res(waterStartTime,waterDuration,landStartTime,landDuration));
    }
};