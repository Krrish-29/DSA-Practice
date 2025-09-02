// 3025. Find the Number of Ways to Place People I
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int size=points.size(),point=0;
        sort(points.begin(),points.end(),[](const vector<int>&a1,const vector<int> &a2){
            return a1[0]==a2[0]?a1[1]>a2[1]:a1[0]<a2[0];
        });
        for(int i=0;i<size-1;i++){
            int bt_right=INT_MIN;
            for(int j=i+1;j<size;j++){
                if(points[j][1]<=points[i][1]&&points[j][1]>bt_right){
                    point++;
                    bt_right=points[j][1];
                }
            }
        }
        return point;
    }
};  