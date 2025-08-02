class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;

        for (int i = 0; i < nums.size(); i++) {
            minh.push({nums[i], i});
            if (minh.size() > k) {
                minh.pop();
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh2;
        vector<int> res;
        
        while (!minh.empty()) {
            auto [num, idx] = minh.top();
            minh.pop();
            minh2.push({idx, num});
        }

        while (!minh2.empty()) {
            auto [x,y] = minh2.top();
            minh2.pop();
            res.push_back(y);
        }

        return res;
    }
};