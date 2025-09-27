// 812. Largest Triangle Area
class Solution {
private:
    double max(double a ,double b){
        if(a<b) return b;
        return a;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int size=points.size();
        double answer=0;
        for(int i=0;i<size-2;i++){
            for(int j=i+1;j<size-1;j++){
                for(int k=j+1;k<size;k++){
                    answer=max(
                        0.5*abs(((points[i][0])*(points[j][1]-points[k][1]))+
                        ((points[j][0])*(points[k][1]-points[i][1]))+
                        ((points[k][0])*(points[i][1]-points[j][1])))
                        ,answer);
                }
            }
        }
        return answer;
    }
};