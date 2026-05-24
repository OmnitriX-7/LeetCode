class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int mx = *max_element(citations.begin(), citations.end());
        vector<int> count(mx+1,0);
        for (int i = 0; i < n; i++) count[citations[i]]++;
        for (int i = mx-1; i >= 0; i--) count[i] += count[i+1];
        for (int i = mx; i >= 0; i--) {
            if (count[i] >= i) return i;
        }
        return 0;
    }
};