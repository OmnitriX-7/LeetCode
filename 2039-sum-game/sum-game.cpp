class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left = 0, sumLeft = 0, right = 0, sumRight = 0;

        for (int i = 0; i < n; i++) {
            if (i < n/2) {
                if (num[i] == '?') left++;
                else sumLeft += num[i]-'0';
            }
            else {
                if (num[i] == '?') right++;
                else sumRight += num[i]-'0';
            }
        }

        if ((left+right) % 2) return 1;

        return (sumLeft-sumRight == ((right-left)/2)*9) ? 0 : 1;
    }
};