class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, star = 0;
        // pass 1: handle extra ')'
        for (char c : s) {
            if (c == '(') open++;
            else if (c == '*') star++;
            else { // ')'
                if (open > 0) open--;
                else if (star > 0) star--;
                else return false;
            }
        }

        open = 0; star = 0;
        // pass 2: handle extra '('
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') open++;
            else if (s[i] == '*') star++;
            else { // '('
                if (open > 0) open--;
                else if (star > 0) star--;
                else return false;
            }
        }

        return true;
    }
};