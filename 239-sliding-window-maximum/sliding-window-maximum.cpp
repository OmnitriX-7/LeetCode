class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> idx;
        vector<int> res;
        int n = nums.size();
        for (int i=0; i<k; i++){
            while (!idx.empty() && nums[idx.back()] <= nums[i]){
                idx.pop_back();
            }
            idx.push_back(i);
        }
        for (int i=k; i<n; i++){
            res.push_back(nums[idx.front()]);
            while (!idx.empty() && nums[idx.back()] <= nums[i]){
                idx.pop_back();
            }
            idx.push_back(i);
            if (idx.back() - idx.front()+1 > k){
                idx.pop_front();
            }
        }
        res.push_back(nums[idx.front()]);
        return res;
    }
};