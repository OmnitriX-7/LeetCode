class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s(nums.begin(), nums.end());
        int n = original;
        for (auto i : s){
            if (s.find(n) != s.end()){
                n *= 2;
            }
            else break;
        }
        return n;
    }
};