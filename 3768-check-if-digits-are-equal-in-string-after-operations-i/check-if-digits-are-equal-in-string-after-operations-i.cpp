class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> vec;
        for (auto c : s) vec.push_back(c-'0');

        int n = vec.size();
        for (int i=n-1; i>1; i--){
            for (int j = 0; j<i; j++)
                vec[j] = (vec[j]+vec[j+1]) % 10;
        }
        if (vec[0] == vec[1]) return true;
        return false;
    }
};