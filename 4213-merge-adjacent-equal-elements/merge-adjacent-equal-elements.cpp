class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        for (auto i : nums){
            if (!st.empty() && st.top() == i){
                long long sum = st.top() + i;
                st.pop();
                while (!st.empty() && st.top() == sum){
                    sum += sum;
                    st.pop();
                }
                st.push(sum);
            }
            else st.push(i);
        }
        
        vector<long long> v;
        while (!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};