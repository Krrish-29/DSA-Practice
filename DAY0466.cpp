// 3951. Minimum Energy to Maintain Brightness
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        // just compress the intervals 
        vector<pair<int,int>>durations;
        sort(intervals.begin(),intervals.end());
        int size=intervals.size(),start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<size;i++){
            if(end<intervals[i][0]){
                durations.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                end=max(end,intervals[i][1]);
            }
        }
        durations.push_back({start,end});
        // for each interval do end-start+1 to get duration and sicne each bulb does lights 3 spaces do ceil (brightness/3.0) * duration for the energy req in the time period
        long long energy=0;
        for(auto &interval:durations){
            energy+=ceil(brightness/3.0)*(interval.second-interval.first+1);
        }
        return energy;
    }
};