class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> intervals;
        map<char, vector<int>> idx;
        for (int i = 0; i < s.size(); i++){
            idx[s[i]].push_back(i);
        }
        for (auto i : idx){
            intervals.push_back({i.second[0], i.second[i.second.size()-1]});
        }

        vector<int> final;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        int start = intervals[0].first;
        int end = intervals[0].second;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first < end){
                end = max(end, intervals[i].second);
            }
            else {
                final.push_back(end-start+1);
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }
        final.push_back(end-start+1);
        return final;
    }
};