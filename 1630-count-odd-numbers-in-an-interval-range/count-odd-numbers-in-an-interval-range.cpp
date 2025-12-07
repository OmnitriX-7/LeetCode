class Solution {
public:
    int countOdds(int low, int high) {
        int l = high-low+1;
        if (low % 2 == 1 && l % 2 == 1) return l/2 + 1;
        return l/2;
    }
};