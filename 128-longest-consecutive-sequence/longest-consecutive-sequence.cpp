class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (auto& num : s) {
            if (!s.count(num-1)) {
                int temp = num;
                int len = 1;
                while (s.count(temp+1)) {
                    temp++;
                    len++;
                }
                ans = max(ans, len);
            }
        }

        return ans;
    }
};