class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> freq;
        vector<int> v;
        for (auto i : nums) freq[i]++;
        for (auto i : freq){
            if (i.second == 2) v.push_back(i.first);
        }
        return v;
    }
};