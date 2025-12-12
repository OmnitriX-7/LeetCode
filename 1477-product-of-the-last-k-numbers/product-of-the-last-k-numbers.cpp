class ProductOfNumbers {
public:
    vector<int> suffix_pro;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            suffix_pro.clear();
        }
        else if (suffix_pro.empty()) suffix_pro.push_back(num);
        else suffix_pro.push_back(suffix_pro.back() * num);
    }
    
    int getProduct(int k) {
        if (suffix_pro.size() < k) return 0;
        else if (suffix_pro.size() == k) return suffix_pro.back();
        return suffix_pro.back()/suffix_pro[suffix_pro.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */