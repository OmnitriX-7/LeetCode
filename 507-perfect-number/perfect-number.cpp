class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num == 1) return 0;
        for (int i = 2; i * i <= num; i++){
            if (num % i == 0){
                sum += i;
                if (num/i != i){
                    sum += num/i;
                }
            }
        }
        return sum+1 == num;
    }
};