class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int mx = INT_MIN;
        for (int i = 0; i < n; i++){
            pq.push({nums[i][0], {i, 0}});
            mx = max(mx, nums[i][0]);
        }

        int start = 0;
        int end = INT_MAX;

        while (pq.size() == n){
            int el = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (mx - el < end - start) {
                start = el;
                end = mx;
            }

            if (j < nums[i].size()-1){
                pq.push({nums[i][j+1], {i, j+1}});
                mx = max(mx, nums[i][j+1]);
            }
        }

        return {start, end};
    }
};