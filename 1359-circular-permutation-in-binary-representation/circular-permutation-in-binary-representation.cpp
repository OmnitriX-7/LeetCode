class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> gray;
        int idx = 0;

        for (int i = 0; i < (1 << n); i++){
            int y = i ^ (i >> 1);  
            if (start == y) idx = i;
            gray.push_back(y);
        }

        vector<int> final;
        int size = 0;

        while (size != gray.size()){
            final.push_back(gray[idx]);   
            idx = (idx + 1) % gray.size(); 
            size++;
        }

        return final;
    }
};
