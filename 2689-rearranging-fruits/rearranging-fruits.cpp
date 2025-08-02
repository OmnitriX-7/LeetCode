class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> extra1, extra2;
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1;
            int times = abs(count) / 2;
            if (count > 0) while (times--) extra1.push_back(fruit);
            else while (times--) extra2.push_back(fruit);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        int globalMin = min(*min_element(basket1.begin(), basket1.end()),*min_element(basket2.begin(), basket2.end()));

        long long totalCost = 0;
        for (int i = 0; i < extra1.size(); i++) {
            int a = extra1[i], b = extra2[i];
            totalCost += min(min(a, b), 2 * globalMin);
        }

        return totalCost;
    }
};
