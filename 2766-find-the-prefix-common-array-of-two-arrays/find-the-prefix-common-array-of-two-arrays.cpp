class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> idx(n+1);
        for (int i = 0; i < n; i++) {
            idx[A[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (i > idx[B[i]]) idx[B[i]] = i;
        }
        vector<int> pre(n);
        for (int i = 1; i <= n; i++) pre[idx[i]]++;
        for (int i = 1; i < n; i++) pre[i] += pre[i-1];
        return pre;
    }
};