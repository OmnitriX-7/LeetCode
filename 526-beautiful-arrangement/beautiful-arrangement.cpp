class Solution {
public:
    vector<int> curr;

    void generate(int mask, int& total, int n) {
        int pos = curr.size()+1;
        if (pos == n+1) {
            total++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {  
                if (pos % (i+1) == 0 || (i+1) % pos == 0) {
                    curr.push_back(i + 1);
                    generate(mask | (1 << i), total, n);
                    curr.pop_back();
                }
            }
        }
    }

    int countArrangement(int n) {
        int total = 0;
        generate(0, total, n);
        return total;
    }
};