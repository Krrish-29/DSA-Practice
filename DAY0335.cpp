// 3197. Find the Minimum Area to Cover All Ones II
class Solution {
private:
    int getRectArea(int startRow,int endRow,int startCol,int endCol,vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size();
        int minRow=m,maxRow=-1,minCol=n,maxCol=-1;
        for(int i=startRow;i<endRow;i++){
            for(int j=startCol;j<endCol;j++){
                if(grid[i][j]==1){
                    minRow=min(minRow,i);
                    maxRow=max(maxRow,i);
                    minCol=min(minCol,j);
                    maxCol=max(maxCol,j);
                }
            }
        }
        return (maxRow-minRow+1)*(maxCol-minCol+1);
    }
    int getAns(vector<vector<int>>&grid){
        int row=grid.size(),col=grid[0].size();
        int ans=INT_MAX;
        for(int rowsplit=1;rowsplit<row;rowsplit++){
            for(int colspilt=1;colspilt<col;colspilt++){
                int top=getRectArea(0,rowsplit,0,col,grid);
                int bottomleft=getRectArea(rowsplit,row,0,colspilt,grid);
                int bottomright=getRectArea(rowsplit,row,colspilt,col,grid);
                ans=min(ans,top+bottomleft+bottomright);
                
                int bottom=getRectArea(rowsplit,row,0,col,grid);
                int topleft=getRectArea(0,rowsplit,0,colspilt,grid);
                int topright=getRectArea(0,rowsplit,colspilt,col,grid);
                ans=min(ans,bottom+topleft+topright);

            }
            for(int rowsplit2=rowsplit+1;rowsplit2<row;rowsplit2++){
                int top=getRectArea(0,rowsplit,0,col,grid);
                int mid=getRectArea(rowsplit,rowsplit2,0,col,grid);
                int bottom=getRectArea(rowsplit2,row,0,col,grid);
                ans=min(ans,top+mid+bottom);
            }
        }
        return ans;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>rotatedGrid(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rotatedGrid[j][m-i-1]=grid[i][j];
            }
        }
        return min(getAns(grid),getAns(rotatedGrid));
    }
};