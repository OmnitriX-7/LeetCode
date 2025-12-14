class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long total = accumulate(balance.begin(), balance.end(), 0LL);
        if (total < 0) return -1;
        int idx = -1;
        for (int i = 0; i < balance.size(); i++){
            if (balance[i] < 0){
                idx = i;
                break;
            }
        }

        if (idx == -1) return 0;

        int p = (((idx-1) % n) + n) % n;
        int q = (idx+1) % n;
        long long c = 0;

        while (balance[idx] < 0) {
            long long d = min(abs(idx-p), n-(abs(idx-p)));
            long long give = min(balance[p], abs(balance[idx]));
            balance[idx] += give;
            c += (d * give);
            if (balance[idx] < 0){
                long long d1 = min(abs(idx-q), n-(abs(idx-q)));
                long long give1 = min(balance[q], abs(balance[idx]));
                balance[idx] += give1;
                c += (d1 * give1);
            }
            p = (((p-1) % n) + n) % n;
            q = (q+1) % n;
        }

        return c;
    }
};