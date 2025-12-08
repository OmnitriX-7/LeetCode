class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        for (auto i : nums){
            int x = i;
            for (int j = 2; j*j <= i; j++){
                if (x % j == 0){
                    s.insert(j);
                    while(x % j == 0){
                        x /= j;
                    }
                }
            }
            if (x > 1) s.insert(x);
        }
        return s.size();
    }
};