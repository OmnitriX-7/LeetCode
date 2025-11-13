class Solution {
public:
    bool isPrime(int num){
        if (num == 1) return 0;
        for (int i = 2; i*i <= num; i++){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for (i; i < n; i++){
            if (isPrime(nums[i])) break;
        }
        int j = n-1;
        for (j; j >= 0; j--){
            if (isPrime(nums[j])) break;
        }
        return j - i;
    }
};