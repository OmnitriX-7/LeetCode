class Solution {
public:
    vector<double> res;
    multiset<int> min_half; 
    multiset<int> max_half; 

    void adding(int n){
        if (min_half.empty() || n <= *min_half.rbegin()) {
            min_half.insert(n);
        } else {
            max_half.insert(n);
        }

        if (min_half.size() > max_half.size() + 1) {
            max_half.insert(*min_half.rbegin());
            min_half.erase(prev(min_half.end()));
        } else if (max_half.size() > min_half.size()) {
            min_half.insert(*max_half.begin());
            max_half.erase(max_half.begin());
        }
    }

    void removing(int n) {
        if (min_half.find(n) != min_half.end()) {
            min_half.erase(min_half.lower_bound(n));
        } else {
            max_half.erase(max_half.lower_bound(n));
        }

        if (min_half.size() > max_half.size() + 1) {
            max_half.insert(*min_half.rbegin());
            min_half.erase(prev(min_half.end()));
        } else if (max_half.size() > min_half.size()) {
            min_half.insert(*max_half.begin());
            max_half.erase(max_half.begin());
        }
    }

    double get_median(int k) {
        if (k % 2 == 1) {
            return *min_half.rbegin();
        } else {
            return ((double)*min_half.rbegin() + *max_half.begin()) / 2.0;
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            adding(nums[i]);
        }
        res.push_back(get_median(k));

        for (int i = k; i < nums.size(); i++) {
            removing(nums[i - k]);
            adding(nums[i]);
            res.push_back(get_median(k));
        }

        return res;
    }
};
