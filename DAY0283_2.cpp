// 840. Magic Squares In Grid
class Solution {
private:
    bool check(vector<vector<int>>&grid,int i,int j){
        vector<bool>seen(10,false);
        for(int row=-1;row<=1;row++){
            for(int col=-1;col<=1;col++){
                if(grid[i+row][j+col]>9||grid[i+row][j+col]<1) return false;
                if(seen[grid[i+row][j+col]]) return false;
                seen[grid[i+row][j+col]]=true;
            }
        }
        int sum=grid[i-1][j-1]+grid[i][j]+grid[i+1][j+1];
        if(
            (grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1])==sum && //row1
            (grid[i-1][j]+grid[i][j]+grid[i+1][j])==sum && //row2
            (grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1])==sum && //row3
            (grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1])==sum && //col1
            (grid[i][j-1]+grid[i][j]+grid[i][j+1])==sum && //col2
            (grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1])==sum && //col3
            (grid[i-1][j-1]+grid[i][j]+grid[i+1][j+1])==sum && //diag1
            (grid[i+1][j-1]+grid[i][j]+grid[i-1][j+1])==sum //diag2
        ) return true;
        return false;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),count=0;
        if(m<3||n<3) return 0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(check(grid,i,j)) count++;
            }
        }
        return count;
    }
};