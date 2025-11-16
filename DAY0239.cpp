// 452. Minimum Number of Arrows to Burst Balloons
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int size=points.size();
        sort(points.begin(),points.end());
        int start=points[0][0],end=points[0][1],count=0;
        for(int i=1;i<size;i++){
            if(end>=points[i][0]&&start<=points[i][0]&&end<points[i][1]){// one side overlapping
                start=points[i][0];
            }
            else if(end>=points[i][1]&&start<=points[i][0]){// both sides overlapping
                start=points[i][0];
                end=points[i][1];
            }
            else if(end<points[i][0]){//no overlapping
                count++;
                start=points[i][0];
                end=points[i][1];
            }
        }
        return count+1;
    }
};