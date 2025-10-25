class Solution {
public:
    int totalMoney(int n) {
        int cnt = 0;
        int k = 1;
        int inc = 0;
        int total = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt == 7) {
                cnt = 0;
                inc++;
                k = 1;
            }
            total += (inc + k);
            k++;
            cnt++;
        }
        return total;
    }
};