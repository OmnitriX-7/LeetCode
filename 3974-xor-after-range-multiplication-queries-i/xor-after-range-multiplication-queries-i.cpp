class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& it : queries) {
            int idx = it[0];
            for (idx; idx <= it[1]; idx += it[2]) {
                nums[idx] = (1LL*(nums[idx] % 1000000007) * (it[3] % 1000000007)) % (1000000007);
            }
        }

        int xorr = 0;
        for (auto i : nums) {
            xorr ^= i;
        }
        return xorr;
    }
};