class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        for (auto& c : text) mp[c]++;

        int ans = INT_MAX;
        vector<char> letters = {'b', 'a', 'l', 'o', 'n'};
        for (auto& i : letters) {
            if (i == 'b' || i == 'a' || i == 'n') ans = min(ans, mp[i]);
            else ans = min(ans, mp[i]/2);
        }
        return ans;
    }
};