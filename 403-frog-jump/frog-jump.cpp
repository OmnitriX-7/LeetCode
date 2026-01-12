class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n, 0);
        vector<set<int>> reach(n);

        if (stones[1] != 1) return false;  

        dp[1] = 1;
        reach[1].insert(1);

        for (int i = 2; i < n; i++){
            for (int j = 1; j < i; j++){
                if (dp[j]){
                    int diff = stones[i] - stones[j];

                    if (reach[j].count(diff-1) || reach[j].count(diff) || reach[j].count(diff+1)) {                      
                        dp[i] = 1;
                        reach[i].insert(diff);   
                    }
                }
            }
        }
        return dp[n-1]; 
    }
};
