class Solution {
public:
    const int MOD = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int evens = 1;
        int odds = 0;
        int sum = 0;
        int c = 0;
        for (auto i : arr){
            sum += i;

            if (sum % 2){
                c = (c+evens) % MOD;
                odds++;
            }
            else {
                c = (c + odds) % MOD;
                evens++;
            }
        }
        return c;
    }
};