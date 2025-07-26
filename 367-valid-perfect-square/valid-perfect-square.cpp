class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 2;
        int j = num/2;
        
        if (num == 1) return 1;

        while (i <= j) {
            long long mid = i + (j-i)/2;

            if (mid*mid == num) {
                return true;
            }
            else if (mid*mid > num) {
                j = mid-1;
            }
            else {
                i = mid+1;
            }
        }
        return false;
    }
};