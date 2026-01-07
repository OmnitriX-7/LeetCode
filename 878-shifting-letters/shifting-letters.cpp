class Solution {
public:
    char addChar(char c, int k){
        return char('a' + ((c - 'a' + k) % 26));
    }

    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long long> suf(n+1, 0);
        for (int i = n-1; i >= 0; i--){
            suf[i] = suf[i+1] + shifts[i];
        }

        for (int i = 0; i < n; i++){
            s[i] = addChar(s[i], suf[i] % 26);
        }
        return s;
    }
};