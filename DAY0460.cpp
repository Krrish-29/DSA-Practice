// 3964. Minimum Lights to Illuminate a Road
class Solution {
public:
    int minLights(vector<int>& lights) {
        // we have some bulbs already lit and we have to find extra bulbs required
        vector<pair<int,int>>intervals;
        int size=lights.size();
        for(int i=0;i<size;i++){
            if(lights[i]!=0){
                intervals.push_back({max(0,i-lights[i]),min(size-1,i+lights[i])});
            }
        }
        sort(intervals.begin(),intervals.end());
        int count=0,start=0,interval=0;
        for(int i=0;i<intervals.size();i++){
            if(start<intervals[i].first){
                interval=intervals[i].first-start;
                count+=ceil(interval/3.0);
            }
            start=max(start,intervals[i].second+1);
        }

        interval=size-start;
        count+=ceil(interval/3.0);
        return count;
    }
};