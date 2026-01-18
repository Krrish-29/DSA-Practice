// 1895. Largest Magic Square
class Solution {
private:
    vector<vector<int>>prefixRow;
    vector<vector<int>>prefixCol;
    bool checkSquare(int row,int col,int size,vector<vector<int>>&grid,int m,int n){
        int diag1=0,diag2=0;
        for(int i=0;i<size;i++){
            diag1+=grid[row+i][col+i];
            diag2+=grid[row+i][col+size-1-i];
        }
        if(diag1!=diag2) return false;
        int rowSum=prefixRow[row][col+size-1]-(col>0?prefixRow[row][col-1]:0);
        int colSum=prefixCol[row+size-1][col]-(row>0?prefixCol[row-1][col]:0);
        for(int i=row+1;i<row+size;i++) if(rowSum!=prefixRow[i][col+size-1]-(col>0?prefixRow[i][col-1]:0)) return false;
        for(int j=col+1;j<col+size;j++) if(colSum!=prefixCol[row+size-1][j]-(row>0?prefixCol[row-1][j]:0)) return false;
        if(rowSum!=colSum||rowSum!=diag1||colSum!=diag1) return false;
        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),size=min(m,n);
        prefixRow=grid;
        prefixCol=grid;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                prefixRow[i][j]+=prefixRow[i][j-1];      
            }
        }
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                prefixCol[i][j]+=prefixCol[i-1][j];      
            }
        }
        while(--size>0){
            for(int row=0;row<m-size;row++){
                for(int col=0;col<n-size;col++){
                    if (checkSquare(row,col,size+1,grid,m,n)) return size+1;
                }
            }
        }
        return 1;
    }
};