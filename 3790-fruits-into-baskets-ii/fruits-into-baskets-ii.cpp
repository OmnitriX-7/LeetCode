class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> visited(baskets.begin(), baskets.end());
        int cnt = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (baskets[j] >= fruits[i] && visited[j] > 0) {
                    cnt--;
                    visited[j] = -visited[j];
                    break;
                }
            }
        }
        return cnt;
    }
};