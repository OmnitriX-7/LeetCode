class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int prev_start = intervals[0][0];
        int prev_end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];

            if (cur_start <= prev_end) {
                prev_end = max(prev_end, cur_end);
            }
            else {
                ans.push_back({prev_start, prev_end});
                prev_start = cur_start;
                prev_end = cur_end;
            }
        }

        ans.push_back({prev_start, prev_end});

        return ans;
    }
};