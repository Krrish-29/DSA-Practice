// 3986. Number of Elapsed Seconds Between Two Times
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int sec=(endTime[6]*10+endTime[7])-(startTime[6]*10+startTime[7]);
        int min=(endTime[3]*10+endTime[4])-(startTime[3]*10+startTime[4]);
        int hour=(endTime[0]*10+endTime[1])-(startTime[0]*10+startTime[1]);
        return hour*60*60+min*60+sec;
    }
};