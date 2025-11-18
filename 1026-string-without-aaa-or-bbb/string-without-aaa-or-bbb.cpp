class Solution {
public:
    string strWithout3a3b(int a, int b) {
        char A = 'a', B = 'b';
        if (b > a) {
            swap(a, b);
            swap(B, A);
        }

        string s;

        while (a || b){
            bool place;
            if (s.size() >= 2 && s[s.size()-1] == A && s[s.size()-2] == A){
                place = 0;
            }
            else if (a == 0) place = 0;
            else if (b == 0) place = 1;
            else place = a >= b;

            if (place) {
                s += A;
                a--;
            }
            else {
                s += B;
                b--;
            }
        }

        return s;
    }
};