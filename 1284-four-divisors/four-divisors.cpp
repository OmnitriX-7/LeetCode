class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++){
            long long sum = 0;
            int c = 0;
            for (int j = 1; j*j <= nums[i]; j++){
                if (nums[i] % j == 0){
                    c++; sum += j;
                    if (nums[i]/j != j){
                        c++; sum += nums[i]/j;
                    }
                }
            }
            if (c == 4) ans += sum;
        }

        return ans;
    }
};