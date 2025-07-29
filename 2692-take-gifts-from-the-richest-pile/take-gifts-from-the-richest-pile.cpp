class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxh(gifts.begin(), gifts.end());
        while (k--) {
            int top = maxh.top();
            maxh.pop();
            int n = floor(sqrt(top));
            maxh.push(n);
        }

        long long x = 0;
        while(!maxh.empty()){
            x += maxh.top();
            maxh.pop();
        }
        return x;
    }
};