class Solution {
public:
    double angleClock(int hour, int minutes) {

        double m = minutes * 6.0;

        double n = (hour % 12) * 30.0 + (minutes * 0.5);

        double diff = abs(m - n);
        return min(diff, 360.0 - diff);
    }
};