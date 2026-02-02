class Solution {
public:
    struct Slider {
        int K;
        multiset<int> lo, hi;
        long long lo_sum = 0;
        
        Slider(int k) {
            K = k;
        }

        void balance() {
            while (lo.size() > K) {
                auto it = prev(lo.end());
                int last = *it;
                lo.erase(it);
                hi.insert(last);
                lo_sum -= last;
            }
            while (lo.size() < K && !hi.empty()) {
                auto it = hi.begin();
                int first = *it;
                hi.erase(it);
                lo.insert(first);
                lo_sum += first;
            }
        }

        void add(int x) {
            if (lo.empty() || *lo.rbegin() >= x) {
                lo.insert(x);
                lo_sum += x;
            } else {
                hi.insert(x);
            }
            balance();
        }

        void remove(int x) {
            auto it_lo = lo.find(x);
            if (it_lo != lo.end()) {
                lo.erase(it_lo);
                lo_sum -= x;
            } else {
                auto it_hi = hi.find(x);
                if (it_hi != hi.end()) {
                    hi.erase(it_hi);
                }
            }
            balance();
        }

        long long query() {
            return lo_sum;
        }
    };

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        k -= 1;
        Slider window(k);
        
        for (int i = 1; i <= 1+dist; i++) {
            window.add(nums[i]);
        }
        
        long long ans = window.query();
        
        for (int i = 2; i + dist < n; i++) {
            window.remove(nums[i-1]);
            window.add(nums[i+dist]);
            ans = min(ans, window.query());
        }
        return ans + nums[0];
    }
};