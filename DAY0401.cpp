// 1559. Detect Cycles in 2D Grid
class Solution {
private:
    vector<vector<int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int m,n;
    vector<vector<bool>>seen;
    bool dfs(vector<vector<char>>& grid,int x,int y,int parent_x,int parent_y){
        seen[x][y]=true;    
        for(auto &dir:dirs){
            int newX=x+dir[0],newY=y+dir[1];
            if(newX>=0&&newX<m&&newY>=0&&newY<n&&grid[x][y]==grid[newX][newY]){
                if(!seen[newX][newY]) {
                    if(dfs(grid,newX,newY,x,y)) return true;
                }
                // seen and are not parent that is why cycle 
                else if(!(newX==parent_x&&newY==parent_y)) return true;
            }
        }
        return false;
    }
    bool bfs(vector<vector<char>> &grid,int x,int y,vector<vector<bool>>& seen){
        seen[x][y]=true;
        queue<vector<int>>q;
        q.push({x,y,-1,-1});
        while(!q.empty()){
            auto e=q.front();q.pop();
            for(auto &dir:dirs){
                int newX=e[0]+dir[0],newY=e[1]+dir[1],parent_x=e[2],parent_y=e[3];
                if(newX>=0&&newX<m&&newY>=0&&newY<n&&grid[x][y]==grid[newX][newY]){
                    if(!seen[newX][newY]) {
                        seen[newX][newY]=true;
                        q.push({newX,newY,e[0],e[1]});
                    }
                    // seen and are not parent that is why cycle 
                    else if(!(newX==parent_x&&newY==parent_y)) return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size(),n=grid[0].size();
        seen.resize(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!seen[i][j]){
                    if(dfs(grid,i,j,-1,-1)) return true;
                    // if(bfs(grid,i,j,seen)) return true;
                }
            }
        }
        return false;
    }
};