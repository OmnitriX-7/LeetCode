class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = (nums[0] == 1) ? 1:-1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0){
                prefix[i] = prefix[i-1]-1;
            }
            else prefix[i] = prefix[i-1]+1;
        }
        int ans = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(prefix[i]) != mp.end()) ans = max(ans, i-mp[prefix[i]]);
            else mp[prefix[i]] = i;
            if (prefix[i] == 0) ans = max(ans, i+1);
        }
        return ans;
    }
};