class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int global_max = arrays[0][arrays[0].size()-1];
        int global_min = arrays[0][0];
        int n = arrays.size();
        int ans = 0;

        for (int i = 1; i < n; i++){
            ans = max(ans, abs(global_max - arrays[i][0]));
            ans = max(ans, abs(arrays[i][arrays[i].size()-1] - global_min));
            global_max = max(global_max, arrays[i][arrays[i].size()-1]);
            global_min = min(global_min, arrays[i][0]);
        }

        return ans;
    }
};