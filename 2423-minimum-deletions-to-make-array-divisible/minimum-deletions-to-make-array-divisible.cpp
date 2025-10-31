class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size();
        int mini = 0;
        for (int i = 0; i < numsDivide.size(); i++) {
            mini = __gcd(mini, numsDivide[i]);
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++){
            if (mini % nums[i] == 0){
                return i;
            }
        }
        return -1;
    }
};