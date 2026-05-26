class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int pos = 0;
        queue<int> q;
        q.push(0);
        int farthest = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == n-1) pos = 1;

            int start = max(farthest+1, cur+minJump);
            int end = min(cur+maxJump, n-1);

            for (int i = start; i <= end; i++) {
                if (s[i] == '0') {
                    q.push(i);
                }
            }
            farthest = end;
        }

        return pos == 1 ? 1 : 0;
    }
};