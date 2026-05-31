class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        int pos = 1;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > m) {
                pos = 0; 
                break;
            }
            m += asteroids[i];
        }

        return pos;
    }
};