class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;
        freq[0]++;
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            ans += freq[rem];
            freq[rem]++;
        }
        return ans;
    }
};