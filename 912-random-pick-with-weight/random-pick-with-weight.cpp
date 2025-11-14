class Solution {
public:
    int n;
    vector<int> w;
    Solution(vector<int>& v) {

        w = v;
                n = w.size();
    }
    
    int pickIndex() {
        random_device rd;
    mt19937 gen(rd());

    discrete_distribution<int> dist(w.begin(), w.end());

    int idx = dist(gen);
    return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */