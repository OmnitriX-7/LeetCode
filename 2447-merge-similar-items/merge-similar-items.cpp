class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto i : items1){
            mp[i[0]] = i[1]; 
        }
        for (auto i : items2){
            if (mp.find(i[0]) != mp.end()){
                mp[i[0]] += i[1];
            }
            else mp[i[0]] = i[1];
        }
        vector<vector<int>> res;
        for (auto i : mp){
            res.push_back({i.first, i.second});
        }
        return res;
    }
};