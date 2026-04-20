class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int p = 0;
        int q = colors.size()-1;
        int ans = 0;

        while (p < q) {
            if (colors[p] != colors[q]) break;
            q--;
        }
        ans = q-p;

        p = 0;
        q = colors.size()-1;
        while (p < q) {
            if (colors[p] != colors[q]) break;
            p++;
        }
        ans = max(ans, q-p);

        return ans;
    }
};