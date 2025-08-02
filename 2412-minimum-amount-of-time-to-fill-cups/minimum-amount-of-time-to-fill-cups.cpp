class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> maxh;
        int cnt = 0;
        for (auto i : amount) {
            if (i > 0){
                maxh.push(i);
            }
        }

        while (!maxh.empty()) {
            if (maxh.size() == 1) {
                cnt += maxh.top();
                break;
            }
            int top = maxh.top();
            maxh.pop();
            int second = maxh.top();
            maxh.pop();
            if (top-1 > 0) maxh.push(top-1);
            if (second-1 > 0) maxh.push(second-1);
            cnt++;
        }

        return cnt;
    }
};