class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        long long c = 0;
        sort(nums.begin(), nums.end());

        for (int i = n-1; i >= 2; i--){
            int x = 0, y = i-1;
            while (x < y){
                if (nums[x] + nums[y] > nums[i]) {
                    c += y-x;
                    y--;
                }
                else x++;
            }
        }
        return c;
    }
};