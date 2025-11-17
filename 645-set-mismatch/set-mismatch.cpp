class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int dup = -1;;
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] == nums[i+1]){
                dup = nums[i];
                break;
            }
        }
        int c = accumulate(nums.begin(), nums.end(),0);
        int miss = n*(n+1)/2 - c + dup;
        return {dup, miss};
    }
};