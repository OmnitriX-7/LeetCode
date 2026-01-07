class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<long long> evenSum(n+1, 0);
        vector<long long> oddSum(n+1, 0);
        int cnt = 0;
        long long currEven = 0;
        long long currOdd = 0;

        for (int i = n-1; i >= 0; i--){
            evenSum[i] = evenSum[i+1];
            oddSum[i]  = oddSum[i+1];

            if (i % 2 == 0) evenSum[i] += nums[i];
            else oddSum[i] += nums[i];
        }

        for (int i = 0; i < n; i++){
            long long netEven = currEven + oddSum[i+1]; 
            long long netOdd  = currOdd  + evenSum[i+1];

            if (netEven == netOdd) cnt++;

            if (i % 2 == 0) currEven += nums[i];
            else currOdd += nums[i];
        }

        return cnt;
    }
};
