class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto i : mp) {
            int sz = i.second.size();
            if (sz >= 3) {
                for (int j = 0; j <= sz-3; j++) {
                    int t = abs(i.second[j]-i.second[j+1]) + abs(i.second[j+1]-i.second[j+2]) + abs(i.second[j]-i.second[j+2]);
                    ans = min(ans, t);
                }
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};