// 2187. Minimum Time to Complete Trips
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        if(time.size()==1) return time[0]*1LL*totalTrips;
        long long low=0,high=*max_element(time.begin(),time.end())*1LL*totalTrips,mid;
        while(low<high){
            mid=low+(high-low)/2;
            long long trips=0;
            for(int &t:time){
                trips+=(mid/t);
            }
            if(trips<totalTrips) low=mid+1;
            else high=mid;
        }
        return low;
    }
};