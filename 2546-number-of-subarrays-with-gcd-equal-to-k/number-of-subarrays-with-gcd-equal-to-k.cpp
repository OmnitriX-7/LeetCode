class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            int g = 0;
            for (int j = i; j < nums.size(); j++){
                g = __gcd(g, nums[j]);
                if (g == k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};