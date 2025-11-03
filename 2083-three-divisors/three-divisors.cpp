class Solution {
public:
    bool isThree(int n) {
        int i = 2;
        for (; i*i < n; i++){
            if (n % i == 0) {
                return false;;
            }
        }
        if (i*i == n && (n % i == 0)) return true;
        return false;
    }
};