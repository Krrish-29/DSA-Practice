// 56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int size=intervals.size();
        vector<vector<int>>merged;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<size;i++){
            if(intervals[i][0]>end){
                merged.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else if(intervals[i][0]<=end&&intervals[i][0]>=start&&intervals[i][1]>=end){
                end=intervals[i][1];
            }
        }
        merged.push_back({start,end});
        return merged;
        
        
        // sort(intervals.begin(),intervals.end());
        // for(int i=1;i<intervals.size();i++){
        //     if(intervals[i][0]<=intervals[i-1][1]&&intervals[i][0]>=intervals[i-1][0]){
        //         intervals[i-1][1]=max(intervals[i-1][1],intervals[i][1]);
        //         intervals.erase(intervals.begin()+i);
        //         i--;
        //     }
        // }
        // return intervals;

    }
};