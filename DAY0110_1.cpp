// 3440. Reschedule Meetings for Maximum Free Time II
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int size=startTime.size();
        vector<vector<int>>intervals(size,vector<int>(2,0));
        for(int i=0;i<size;i++){
            intervals[i][0]=(startTime[i]);
            intervals[i][1]=(endTime[i]);
        }
        sort(intervals.begin(),intervals.end());
        vector<int>gaps;
        gaps.push_back(intervals[0][0]);
        for(int i=1;i<size;i++){
            gaps.push_back(intervals[i][0]-intervals[i-1][1]);
        }
        gaps.push_back(eventTime-intervals[size-1][1]);
        vector<int>maxBefore(size+2,0);
        vector<int>maxAfter(size+2,0);
        for(int i=1;i<=size;i++){
            maxBefore[i]=max(maxBefore[i-1],gaps[i-1]);
        }
        for(int i=size;i>=1;i--){
            maxAfter[i]=max(maxAfter[i+1],gaps[i]);
        }
        int maxFree=0;
        for(int gap:gaps){
            maxFree=max(maxFree,gap);
        }
        for(int i=0;i<size;i++){
            int bestGap=max(i>0?maxBefore[i]:0,i<size-1?maxAfter[i+2]:0);
            if((intervals[i][1]-intervals[i][0])<=bestGap){
                maxFree=max(maxFree,(intervals[i][1]-intervals[i][0])+gaps[i]+gaps[i+1]);
            }
            else{
                maxFree=max(maxFree,gaps[i]+gaps[i+1]);
            }
        }
        return maxFree;
    }
};