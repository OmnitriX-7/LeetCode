class Solution {
public:
    bool canBeEqual(string s1, string s2) {
    vector<char> a = {s1[0], s1[2]};
    vector<char> b = {s2[0], s2[2]};
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a != b) return false;

    a = {s1[1], s1[3]};
    b = {s2[1], s2[3]};
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}
};