// 1970. Last Day Where You Can Still Cross
class Solution {
private:
    bool checkLastDay(int day,vector<vector<int>>&cells,int &row,int &col){
        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i=0;i<=day;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int,int>>queue;
        for(int col0=0;col0<col;col0++){
            if(grid[0][col0]==0) {
                grid[0][col0]=1;
                queue.push({0,col0});
            }
        }
        while(!queue.empty()){
            auto [i,j]=queue.front();queue.pop();
            if(i+1==row) return true;
            if(j>0&&grid[i][j-1]==0) {
                grid[i][j-1]=1;
                queue.push({i,j-1});
            }
            if(j+1<col&&grid[i][j+1]==0) {
                grid[i][j+1]=1;
                queue.push({i,j+1});
            }
            if(i+1<row&&grid[i+1][j]==0) {
                grid[i+1][j]=1;
                queue.push({i+1,j});
            }
            if(i-1>=0&&grid[i-1][j]==0) {
                grid[i-1][j]=1;
                queue.push({i-1,j});
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=0,right=cells.size()-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(checkLastDay(mid,cells,row,col)) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
};