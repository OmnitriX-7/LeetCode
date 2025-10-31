class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        
        for (int i = 0; i < timePoints.size(); i++) {
            int hr_mins = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3, 2));
            mins.push_back(hr_mins*60+minutes);
        }

        sort(mins.begin(), mins.end());
        int mini = INT_MAX;
        for (int i = 1; i < mins.size(); i++){
            mini = min(mini, mins[i]-mins[i-1]);
        }
        mini = min(mini, mins[0]+(1440-mins[mins.size()-1]));
        return mini;
    }
};