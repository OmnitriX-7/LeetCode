class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        int a = 0;
        if (s.find(val) == s.end()) {
            a = 1;
            s.insert(val);
        }
        return a == 1;
    }
    
    bool remove(int val) {
        int b = 0;
        if (s.find(val) != s.end()) {
            b = 1;
            s.erase(val);
        }
        return b == 1;
    }
    
    int getRandom() {
        int r = rand() % s.size();
        auto it = s.begin();
        advance(it, r); 
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */