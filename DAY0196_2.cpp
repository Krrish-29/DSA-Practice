// 695. Max Area of Island
class Solution {
private:
    int row,col;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(grid[i][j]==0) return 0;
        int area=1;
        grid[i][j]=0;
        for(const auto &d:dir){
            if(i+d[0]>=0&&i+d[0]<row&&j+d[1]>=0&&j+d[1]<col) 
                area+=dfs(grid,i+d[0],j+d[1]);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int maxArea=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0) maxArea=max(maxArea,dfs(grid,i,j));
            }
        }
        return maxArea;
    }
};