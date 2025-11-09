class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int i = 1;
        while (pow(5,i) <= n){
            sum += n/pow(5,i);
            i++;
        }
        return sum;
    }
};