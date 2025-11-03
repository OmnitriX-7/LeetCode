class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> idx;
        for (int i = 0; i < groupSizes.size(); i++){
            idx[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto i : idx){
            vector<int> tmp;
            for (int j = 1; j <= i.second.size(); j++){
                tmp.push_back(i.second[j-1]);
                if (j % i.first == 0){
                    res.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        return res;
    }
};