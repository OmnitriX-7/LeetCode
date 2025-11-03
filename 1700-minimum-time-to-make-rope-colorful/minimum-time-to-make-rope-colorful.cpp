class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int t = 0;
        int curr_max = neededTime[0];
        int seg_sum = neededTime[0];
        int n = colors.size();
        for (int i = 1; i < n; i++){
            if (colors[i] != colors[i-1]){
                t += seg_sum-curr_max;
                seg_sum = neededTime[i];
                curr_max = neededTime[i];
            }
            else {
                curr_max = max(curr_max, neededTime[i]);
                seg_sum += neededTime[i];
            }
        }
        t += seg_sum-curr_max;
        return t;
    }
};