class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int sz = a.size();
        int ans = 0, gap = 0, f = 0;
        for (int i = 0; i < sz; i++) {
            if (a[i] == 0) {
                gap++;
            } else {
                if (!f) ans += gap/2;
                else if (gap > 0) ans += (gap-1)/2;
                gap = 0;
                f = 1;
            }
        }
        if (!f) ans += (gap+1)/2;
        else ans += gap/2;
        return ans >= n;
    }
};