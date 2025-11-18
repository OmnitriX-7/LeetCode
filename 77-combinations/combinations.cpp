class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++){
            v.push_back(i);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < (1 << n); i++){
            vector<int> t;
            for (int j = 0; j < n; j++){
                if (i & (1 << j)){
                    t.push_back(v[j]);
                }
            }
            if (t.size() == k) ans.push_back(t);
        }
        return ans;
    }
};