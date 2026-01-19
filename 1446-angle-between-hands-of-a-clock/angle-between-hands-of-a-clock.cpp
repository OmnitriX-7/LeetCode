class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min = 6 * minutes;
        double hr = (30 * (hour%12)) + ((double)minutes/60) * 30; 
        double angle1 = abs(hr-min);
        double angle2 = 360 - angle1;
        if (angle1 < angle2) return angle1;
        return angle2;
    }
};