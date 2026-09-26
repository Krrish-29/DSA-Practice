// 4057. Number of Intersecting Interval Pairs II
class Solution {
private:
    int binary_search(vector<vector<int>>& intervals,int left,int right,int target){
        int mid;
        while(left<=right){
            mid = (right-left)/2 + left;
            if(intervals[mid][0]<=target) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        // sort the intervals and use binary search 
        // with binary search find the idx which is having the intervals[i][0] just bigger than interval[curr][0] 
        // use binary_search_idx - i - 1 since the idx returned will be 1 more than what will actually intersect 
        // also the range for searching will be i to size-1
        // sort(intervals.begin(),intervals.end());
        // int size=intervals.size();
        // long long count=0;
        // for(int i=0;i<size;i++){
        //     count+=(binary_search(intervals,i,size-1,intervals[i][1]) - i - 1);
        // }
        // return count;


        // each interval start and end becomes an event and these events will be sorted based on start or end value ,
        // if [1,2] & [2,3] -> 2 'E' and 2,'S' situation we prefer 2 S before 2 E
        // to count overlapping, whenever we have a start event we increment the number of active events 
        // and the number of active events before the current will all overlap with the current one 
        // so we count them , and decrement if a end event comes  
        vector<pair<int,char>>line;
        for(auto &interval:intervals){
            line.push_back({interval[0],'S'});
            line.push_back({interval[1],'E'});
        }
        sort(line.begin(),line.end(),[](pair<int,char>&a,pair<int,char>&b){
            if(a.first == b.first) return a.second > b.second; // start should be before end ,a.second > b.second since S > E
            return a.first<b.first;
        });
        long long active=0,count=0;
        for(auto &[pos,event]:line){
            if(event=='S'){
                count+=active;
                active++;
            }
            else{
                active--;
            }
        }
        return count;
    }
};