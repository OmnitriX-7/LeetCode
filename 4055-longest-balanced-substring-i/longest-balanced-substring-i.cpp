class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++){
            vector<int> freq(26,0);
            for (int j = i; j < n; j++){
                freq[s[j]-97]++;
                bool flag = 1;
                int target = -1;
                for (int k = 0; k < 26; k++){
                    if (freq[k] > 0){
                        if (target == -1){
                            target = freq[k];
                        }
                        else if (freq[k] != target) {
                            flag = 0;
                            break;
                        }   
                    }
                }
                if (flag) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};