class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        if (n == 1) return 0;
        vector<int> a(n), b(n);
        a[n-1] = (s[n-1] == 'a') ? 1 : 0;
        b[0] = (s[0] == 'b') ? 1 : 0;

        int ans = INT_MAX;
        for (int i = 1; i < n; i++){
            if (s[i] == 'a'){
                b[i] = b[i-1];
            }
            else {
                b[i] = b[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; i--){
            if (s[i] == 'a'){
                a[i] = a[i+1] + 1;
            }
            else {
                a[i] = a[i+1];
            }
        }

        for (int i = 0; i < n; i++){
            if (i == 0) ans = min(ans, a[1]);
            else if (i == n-1) ans = min(ans, b[n-2]);
            else ans = min(ans, b[i-1] + a[i+1]);
        }

        return ans;
    }
};