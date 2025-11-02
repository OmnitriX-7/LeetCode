class Solution {
public:
    int balancedStringSplit(string s) {
        int cr = 0;
        int cl = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'L') cl++;
            else cr++;
            if (cl == cr) res++;
        }
        return res;
    }
};