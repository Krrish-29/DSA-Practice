// 3453. Separate Squares I
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double left=0,right=2e9,mid;
        while(right-left>1e-6){
            mid=left+(right-left)/2.0;
            double upperArea=0,lowerArea=0;
            for(auto & sq:squares){
                if(sq[1]>=mid) upperArea+=(sq[2]*1.0*sq[2]);
                else if(sq[1]+sq[2]<=mid) lowerArea+=(sq[2]*1.0*sq[2]);
                else {
                    upperArea+=(sq[2]*1.0*(sq[1]+sq[2]-mid));
                    lowerArea+=(sq[2]*1.0*(mid-sq[1]));
                }
            }
            if(upperArea>lowerArea) left=mid;
            else right=mid;
        }
        return (left+right)/2;
    }
};