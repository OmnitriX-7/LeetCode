class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        while (i >= 0) {
            if (s[i] != ' ') break;
            i--;
        }
        int j = i-1;
        while (j >= 0) {
            if (s[j] == ' ') break;
            j--;
        }
        return i-j;
    }
};