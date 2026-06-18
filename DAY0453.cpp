// 1344. Angle Between Hands of a Clock
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteDeg=minutes * 6; // 1 minute gives 6 deg
        double hourDeg=(hour%12) * 30 + 30 * (minutes/60.0); // 1 hour gives 30 deg 
        // the extra movement is based on the minute hand 
        // hour hand can move at max 30 deg while minute hand covers 60 min
        // so to find deg in bewteen we do minute/60 to know how much of 30 deg hour hand will move
        return min(abs(hourDeg-minuteDeg),360.0-abs(hourDeg-minuteDeg));
    }
};