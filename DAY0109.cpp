// 3439. Reschedule Meetings for Maximum Free Time I
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int size=startTime.size(),start=0;
        vector<int>freeTime(size+1);
        for(int i=0;i<size;i++){
            freeTime[i]=startTime[i]-start;
            start=endTime[i];
        }
        freeTime[size]=eventTime-start;
        int maxSum=0;
        for(int i=0;i<=size&&i<=k;i++){
            maxSum+=freeTime[i];
        }
        int res=maxSum;
        for(int i=0;k<size;i++,k++){
            maxSum+=(freeTime[k+1]-freeTime[i]);
            res=max(res,maxSum);
        }  
        return res;
    }
};