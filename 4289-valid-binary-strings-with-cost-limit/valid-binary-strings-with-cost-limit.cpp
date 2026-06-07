class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        for (int mask = 0; mask < (1 << n); mask++) {
            string temp;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) temp += '1';
                else temp += '0';
            }
            reverse(temp.begin(), temp.end());
            int pos = 1;
            long long cost = temp[n-1] == '1' ? n-1 : 0;
            for (int i = 0; i < n-1; i++) {
                if (temp[i] == '1' && temp[i+1] == '1') {
                    pos = 0;
                    break;
                }
                else if (temp[i] == '1') cost += i;
            }
            if (pos && cost <= k) res.push_back(temp);
        }
        return res;
    }
};