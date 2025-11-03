class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            long long l = nums[i];
            for (int j = i; j < nums.size(); j++){
                l = lcm(l, 1LL*nums[j]);
                if (l == k) cnt++;
                else if (l > k) break;
            }
        }
        return cnt;
    }
};