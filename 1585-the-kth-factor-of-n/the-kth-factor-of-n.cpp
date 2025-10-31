class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> facts;
        for (int i = 1; i*i <= n; i++){
            if (n % i == 0){
                facts.push_back(i);
                if (i != n/i) facts.push_back(n/i);
            } 
        }
        sort(facts.begin(), facts.end());
        if (facts.size() < k) return -1;
        return facts[k-1];
    }
};