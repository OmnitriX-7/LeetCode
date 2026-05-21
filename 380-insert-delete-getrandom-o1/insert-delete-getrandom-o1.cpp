class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> m;

    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)) {
            return false;
        }
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        int idx = m[val];
        int last = v.back();
        v[idx] = last;
        m[last] = idx;
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};