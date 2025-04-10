// 56. Merge Intervals
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
            for(int i=1;i<intervals.size();i++){
                int upper=intervals[i-1][1],lower=intervals[i-1][0];
                if(lower<=intervals[i][0]&&upper>=intervals[i][1]){
                    intervals[i][0]=intervals[i-1][0];
                    intervals[i][1]=intervals[i-1][1];
                    intervals.erase(intervals.begin()+i-1);
                    i--;
                }
                else if(lower>=intervals[i][0]&&upper<=intervals[i][1]){
                    intervals.erase(intervals.begin()+i-1);
                    i--;
                }
                else if(lower>=intervals[i][0]){
                    intervals[i][1]=intervals[i-1][1];
                    intervals.erase(intervals.begin()+i-1);
                    i--;
                }
                else if(upper>=intervals[i][0]){
                    intervals[i][0]=intervals[i-1][0];
                    intervals.erase(intervals.begin()+i-1);
                    i--;
                }
            }
            return intervals;
        }
    };