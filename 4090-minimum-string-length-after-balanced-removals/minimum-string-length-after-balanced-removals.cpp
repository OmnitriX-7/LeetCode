class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int c = count(s.begin(), s.end(), 'a');
        int c1 = count(s.begin(), s.end(), 'b');
        return s.size() - 2*min(c, c1);
    }
};