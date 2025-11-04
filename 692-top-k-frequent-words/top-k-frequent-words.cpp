class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for (auto i : words){
            freq[i]++;
        }
        vector<pair<int, string>> v;
        for (auto i : freq){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), [](auto& a, auto& b){
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        vector<string> final;
        for (int i = 0; i < k; i++){
            final.push_back(v[i].second);
        }
        return final;
    }
};