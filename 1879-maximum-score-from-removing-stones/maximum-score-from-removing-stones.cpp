class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxh;
        maxh.push(a);
        maxh.push(b);
        maxh.push(c);
        
        int cnt = 0;

        while (maxh.size() > 1){
            int x = maxh.top()-1; maxh.pop();
            int y = maxh.top()-1; maxh.pop();
            if (x >= 1) maxh.push(x);
            if (y >= 1) maxh.push(y);
            cnt++;
        }

        return cnt;
    }
};