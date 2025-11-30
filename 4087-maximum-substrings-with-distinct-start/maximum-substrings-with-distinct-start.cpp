class Solution {
public:
    int maxDistinct(string s) {
        set<int> z(s.begin(), s.end());
        return z.size();
    }
};