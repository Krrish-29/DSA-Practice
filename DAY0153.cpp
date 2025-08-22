// 3195. Find the Minimum Area to Cover All Ones I
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int topI=0,leftI=0,rightI=grid[0].size()-1,bottomI=grid.size()-1;
        bool top=false,bottom=false,left=false,right=false;
        while(topI<=bottomI&&leftI<=rightI){
            for(int j=leftI;j<=rightI&&!top;j++){
                if(grid[topI][j]==1) top=true; 
            }

            for(int i=topI;i<=bottomI&&!right;i++){
                if(grid[i][rightI]==1) right=true; 
            }

            if(topI<=bottomI){
                for(int j=rightI;j>=leftI&&!bottom;j--){
                    if(grid[bottomI][j]==1) bottom=true; 
                }
            }
            if(leftI<=rightI){
                for(int i=bottomI;i>=topI&&!left;i--){
                    if(grid[i][leftI]==1) left=true; 
                }
            }
            if(!top) topI++;
            if(!right) rightI--;
            if(!left) leftI++;
            if(!bottom) bottomI--;
            if(top&&right&&left&&bottom) break;
        }
        return (rightI-leftI+1)*(bottomI-topI+1);
    }
};