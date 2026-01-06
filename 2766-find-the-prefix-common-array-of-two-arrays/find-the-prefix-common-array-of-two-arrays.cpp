class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> seenA(n+1, 0), seenB(n+1, 0), C(n);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (++seenA[A[i]] == 1 && seenB[A[i]] == 1) cnt++;
            if (++seenB[B[i]] == 1 && seenA[B[i]] == 1) cnt++;
            C[i] = cnt;
        }
        return C;
    }
};
