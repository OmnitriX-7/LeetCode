class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        priority_queue<int> maxh; 
        int n = arr.size();
        int cnt = 0;
        int f = 0;
        for (auto i : arr){
            freq[i]++;
        }
        for (auto i : freq){
            maxh.push(i.second);
        }
        while (!maxh.empty()){
            cnt += maxh.top();
            maxh.pop();
            f++;
            if (cnt >= n/2) break;
        }
        return f;
    }
};