// 200. Number of Islands
class Solution {
private:
    vector<vector<int>>dirs={{-1,0},{1,0},{0,1},{0,-1}};
    int m,n;
    void bfs(vector<vector<char>> &grid,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(auto &dir:dirs){
                int newX=dir[0]+x,newY=dir[1]+y;
                if(newX>=0&&newX<m&&newY>=0&&newY<n&&grid[newX][newY]=='1') {
                    grid[newX][newY]='0';
                    q.push({newX,newY});
                }
            }
        }
    }
    void dfs(int i,int j,vector<vector<char>> &grid){
        for(auto &dir:dirs){
            int newX=dir[0]+i,newY=dir[1]+j;
            if(newX>=0&&newX<m&&newY>=0&&newY<n&&grid[newX][newY]=='1') {
                grid[newX][newY]='0';
                dfs(newX,newY,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(),n=grid[0].size();
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    grid[i][j]='0';
                    dfs(i,j,grid);
                    // bfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};