class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> freq;
        for (auto i : arr) freq[i]++;

        vector<int> v;
        for (auto i : freq){
            v.push_back(i.second);
        }

        sort(v.begin(), v.end());

        int c = freq.size();

        for (auto i : v){
            if (k >= i){
                c--;
                k -= i;
            }
        }
        return c;
    }
};