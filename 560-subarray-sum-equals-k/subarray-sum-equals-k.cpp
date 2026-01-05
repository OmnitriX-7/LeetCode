class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sums;
        sums[0]++;
        long long PreSum = 0;
        int c = 0;
        
        for (int i = 0; i < n; i++){
            PreSum += nums[i];
            if (sums.find(PreSum-k) != sums.end()){
                c += sums[PreSum - k];
            }
            sums[PreSum]++;
        }
        return c;
    }
};