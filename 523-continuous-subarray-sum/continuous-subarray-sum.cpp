class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for (int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        for (auto& i : prefix) i %= k;

        map<int, int> freq;
        for (int i = 1; i <= n; i++) {
            if (i > 1 && prefix[i] == 0) return true;
            if (freq.find(prefix[i]) == freq.end()){
                freq[prefix[i]] = i;
            }
            else {
                if (i - freq[prefix[i]] > 1) return true;
            }
        }
        return false;
    }
};