// 1288. Remove Covered Intervals
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int count=0,end=0;
        for(int i=0;i<intervals.size();i++){
            if(end<intervals[i][1]){
                count++;
                end=intervals[i][1];
            }
        }
        return count;
    }
};