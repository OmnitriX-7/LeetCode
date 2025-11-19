class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int sum  = 0;
        int j = n-2;
        for (int i = 0; i < n/3; i++){
            sum += piles[j];
            j -= 2;
        }
        return sum;
    }
};