// 3047. Find the Largest Area of Square Inside Two Rectangles
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int size=bottomLeft.size();
        long long maxArea=0;
        for(int i=0;i<size;i++){
            int r1x1=bottomLeft[i][0],r1y1=bottomLeft[i][1],r1x2=topRight[i][0],r1y2=topRight[i][1];
            for(int j=i+1;j<size;j++){
                int r2x1=bottomLeft[j][0],r2y1=bottomLeft[j][1],r2x2=topRight[j][0],r2y2=topRight[j][1];
                if(!( r1x2<=r2x1 || r2x2<=r1x1 || r1y2<=r2y1 || r2y2<=r1y1 )){
                    int nrx1=max(r1x1,r2x1),nry1=max(r1y1,r2y1),nrx2=min(r1x2,r2x2),nry2=min(r1y2,r2y2);
                    maxArea=max(maxArea,min(nrx2-nrx1,nry2-nry1)*1LL*min(nrx2-nrx1,nry2-nry1));
                }
            }
        }
        return maxArea;
    }
};