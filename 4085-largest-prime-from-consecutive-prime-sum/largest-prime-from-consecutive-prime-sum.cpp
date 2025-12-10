class Solution {
public:
    int largestPrime(int n) {
        vector<int> sieve(n+1, 1);
        sieve[0] = sieve[1] = 0;
        for (int i = 2; i*i <= n; i++){
            if (sieve[i]){
                for (int j = i*i; j <= n; j+=i){
                    if (sieve[j]) sieve[j] = 0;
                }
            }
        }

        set<int> sum;
        int curr = 0;
        for (int i = 1; i < n+1; i++){
            if (sieve[i]){
                curr += i;
                if (curr > n) break;
                sum.insert(curr);
            }
        }

        for (int i = n; i >=2; i--){
            if (sieve[i] && sum.find(i) != sum.end()) return i;
        }
        return 0;
    }
};