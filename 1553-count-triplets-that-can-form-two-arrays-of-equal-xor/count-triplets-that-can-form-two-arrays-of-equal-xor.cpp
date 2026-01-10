class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n+1, 0);
        int c = 0;
        for (int i = 1; i <= n; i++) pre[i] = pre[i-1] ^ arr[i-1];

        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j < n; j++){
                for (int k = j; k < n; k++){
                    int a = pre[j] ^ pre[i];
                    int b = pre[k+1] ^ pre[j];
                    
                    if (a == b) c++;
                }
            }
        }
        return c;
    }
};