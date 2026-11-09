// 2409. Count Days Spent Together
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // from strings extract month and day of arrive and leave 
        // using which convert them into total days for start and end for both 
        // then using min(end of both) - max(start of both) , tells the overlapping days
        // also use min (0 , above calculation ) to prevent -ve cases for no overlap

        // example alice started on day 207 and ended on day 305
        // bob start on day 105 and ended on day 267 
        // this format is easier to understand and calculate
        int monthStartA = (arriveAlice[0] -'0')*10 + arriveAlice[1] -'0';
        int monthEndA = (leaveAlice[0] -'0')*10 + leaveAlice[1] -'0';

        int monthStartB = (arriveBob[0] -'0')*10 + arriveBob[1] -'0';
        int monthEndB = (leaveBob[0] -'0')*10 + leaveBob[1] -'0';

        int dayStartA = (arriveAlice[3] -'0')*10 + arriveAlice[4] -'0';
        int dayEndA = (leaveAlice[3] -'0')*10 + leaveAlice[4] -'0';

        int dayStartB = (arriveBob[3] -'0')*10 + arriveBob[4] -'0';
        int dayEndB = (leaveBob[3] -'0')*10 + leaveBob[4] -'0';

        vector<int>days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int startA=0,endA=0,startB=0,endB=0;
        for(int month=0;month<monthStartA-1;month++){ // < month  ,adjusting for 1 based indexing, and -1 for going before that month since the days in the statMonth will be given by dayStart
            startA += days[month];
        }
        startA += dayStartA;

        for(int month=0;month<monthEndA-1;month++){
            endA += days[month];
        }
        endA += dayEndA;


        for(int month=0;month<monthStartB-1;month++){
            startB += days[month];
        }
        startB += dayStartB;

        for(int month=0;month<monthEndB-1;month++){
            endB += days[month];
        }
        endB += dayEndB;
        return max(0 , min(endA,endB) - max(startA,startB) + 1);
    }
};  