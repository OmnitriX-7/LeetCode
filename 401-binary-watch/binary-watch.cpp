class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        for (int hr = 0; hr < 12; hr++) {
            for (int min = 0; min < 60; min++) {
                
                if (__builtin_popcount(hr) + __builtin_popcount(min) == turnedOn) {
                    
                    string time = to_string(hr) + ":";
                    
                    if (min < 10) {
                        time += "0";
                    }
                    
                    time += to_string(min);
                    
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};