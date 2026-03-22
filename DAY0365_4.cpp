// 994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int minTime=0;
        vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto ele=q.front();q.pop();
                for(auto &dir:dirs){
                    int newX=dir[0]+ele.first,newY=dir[1]+ele.second;
                    if(newX>=0&&newX<m&&newY>=0&&newY<n&&grid[newX][newY]==1){
                        grid[newX][newY]=2;
                        q.push({newX,newY});
                    } 
                }
            }
            minTime++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return max(minTime-1,0);
    }
};