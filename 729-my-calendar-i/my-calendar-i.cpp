class MyCalendar {
public:
    map<int, int> freq;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (auto i : freq){
            if (startTime >= i.second || endTime <= i.first) continue;
            else return false;
        }
        freq[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */