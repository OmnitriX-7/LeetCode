class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                int p = nums[i] * nums[j];
                cnt += 8 * freq[p];
                freq[p]++;
            }
        }
        return cnt;
    }
};