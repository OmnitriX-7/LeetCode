class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = count(moves.begin(), moves.end(), 'L');
        int r = count(moves.begin(), moves.end(), 'R');
        int dash = count(moves.begin(), moves.end(), '_');

        if (l >= r) return l+dash-r;
        return r+dash-l;
    }
};