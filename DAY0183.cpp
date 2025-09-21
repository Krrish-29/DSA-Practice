// 57. Insert Interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // int size=intervals.size(),start=newInterval[0],end=newInterval[1],i=0,j;
        // while(i<size&&intervals[i][1]<start) i++;
        // j=i;
        // while(i<size&&intervals[i][0]<=end){
        //     start=min(start,intervals[i][0]);
        //     end=max(end,intervals[i][1]);
        //     i++;
        // }
        // if(j<i){
        //     intervals[j]={start,end};
        //     intervals.erase(intervals.begin()+j+1,intervals.begin()+i);
        // }
        // else{
        //     intervals.push_back({start,end});
        // }
        // sort(intervals.begin(),intervals.end());
        // return intervals;
        vector<vector<int>>ans;
        int size=intervals.size();
        int i=0;
        while(i<size&&intervals[i][1]<newInterval[0]) ans.push_back(intervals[i++]);
        while(i<size&&intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back({newInterval[0],newInterval[1]});
        while(i<size) ans.push_back(intervals[i++]);
        return ans;
    }
};