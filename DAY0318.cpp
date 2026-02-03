// 2943. Maximize Area of Square Hole in Grid
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxHeight=1,currHeight=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]!=1) currHeight=1;
            else currHeight++;
            maxHeight=max(maxHeight,currHeight);
        }
        int maxWidth=1,currWidth=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]!=1) currWidth=1;
            else currWidth++;
            maxWidth=max(maxWidth,currWidth);
        }
        return min(maxHeight+1,maxWidth+1)*min(maxHeight+1,maxWidth+1);
    }
};