class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        int j = sqrt(num);
        while (i <= j) {
            int mid = i + (j-i)/2;

            if (mid*mid == num) {
                return true;
            }
            i = mid+1;
        }
        return false;
    }
};