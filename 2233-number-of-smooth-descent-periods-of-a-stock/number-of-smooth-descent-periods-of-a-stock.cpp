class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long total = 0;
        long long seg = 1;
        for (int i = 1; i < n; i++){
            if (prices[i] == prices[i-1]-1) seg++;
            else{
                total += ((seg-1)*(seg)/2);
                seg = 1;
            }
        }
        total += ((seg-1)*(seg)/2);
        return total+n;
    }
};