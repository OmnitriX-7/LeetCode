class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int cnt = 0;
        int max_xor = 0;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            int temp = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp |= nums[i];
                }
            }
            if (temp > max_xor){
                max_xor = temp;
                cnt = 1;
            }
            else if (temp == max_xor) cnt++;
        }
        return cnt;
    }
};