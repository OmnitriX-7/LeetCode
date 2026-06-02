class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = landStartTime[i]+landDuration[i];
                int y = waterStartTime[j]+waterDuration[j];
                int curr1 = x + max(0, waterStartTime[j]-x) + waterDuration[j];
                int curr2 = y + max(0, landStartTime[i]-y) + landDuration[i];
                ans = min(ans, min(curr1, curr2));
            }
        }

        return ans;
    }
};