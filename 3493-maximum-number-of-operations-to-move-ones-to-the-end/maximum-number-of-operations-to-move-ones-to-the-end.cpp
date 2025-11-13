class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int seg = 0;
        int curr = 0;
        int i = n-1;
        int ans = 0;
        char prev = '1';
        for (i; i>=0; i--){
            if (s[i] == '1'){
                ans += seg;
                curr = 0;
            }
            else {
                if (prev == '1'){
                    seg++;
                } 
                curr++;
            }
            prev = s[i];
        }
        return ans;
    }
};