class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        map<int, int> idx;
        for (int i = 0; i < n; i++) idx[nums[i]] = i;

        int ans = 0;

        for (int i = 0; i < n; i++){
            int great = n - idx[nums[i]] - 1;
            if (great >= k) ans++;
        }
        return ans;
    }
};