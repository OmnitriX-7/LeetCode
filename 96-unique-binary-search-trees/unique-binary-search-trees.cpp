class Solution {
public:
    long long fact(long long n){
        long long res = 1;

        for (int i = 1; i <= n; i++) {
            res = res * (n + i) / i;  
        }

        return res / (n + 1);
    }

    int numTrees(int n) {
        return fact(n);
    }
};