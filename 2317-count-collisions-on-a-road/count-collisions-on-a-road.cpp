class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;
        int i = 0, j = n-1;
        for (; i < n; i++) {
            if (directions[i] != 'L') break;
        }
        for (; j >= 0; j--) {
            if (directions[j] != 'R') break;
        }

        for (; i <= j; i++){
            if (directions[i] != 'S') ans++;
        }

        return ans;
    }
};