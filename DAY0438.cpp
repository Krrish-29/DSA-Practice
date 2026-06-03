// 3635. Earliest Finish Time for Land and Water Rides II
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landSize=landStartTime.size();
        int waterSize=waterStartTime.size();
        // weird question looks like binary search and sorting but we need to just
        // get minfinish time for land and water then add with other times from land and other to find best min time
        int minLandTime=INT_MAX,minWaterTime=INT_MAX;
        int bestTime=INT_MAX;
        for(int i=0;i<landSize;i++){
            if(landStartTime[i]+landDuration[i]<minLandTime) minLandTime=landStartTime[i]+landDuration[i];
        }
        for(int i=0;i<waterSize;i++){
            bestTime=min(bestTime,max(waterStartTime[i],minLandTime)+waterDuration[i]);
        }
        for(int i=0;i<waterSize;i++){
            if(waterStartTime[i]+waterDuration[i]<minWaterTime) minWaterTime=waterStartTime[i]+waterDuration[i];
        }
        for(int i=0;i<landSize;i++){
            bestTime=min(bestTime,max(landStartTime[i],minWaterTime)+landDuration[i]);
        }
        return bestTime;
    }
};