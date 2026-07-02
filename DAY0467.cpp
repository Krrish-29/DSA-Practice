// 3286. Find a Safe Walk Through a Grid
class Solution {
private:
    struct hash{
        size_t operator()(const pair<int,int>& p)const {
            return (31*p.first)^p.second;
        }
    };
    int m,n;
    vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<vector<int>>>dp;
    bool dfs(vector<vector<int>>& grid, int health,int x,int y,unordered_set<pair<int,int>,hash>& seen){
        if(x==m-1&&y==n-1&&health>=1) return dp[x][y][health]=true;
        if(dp[x][y][health]!=-1) return dp[x][y][health];
        if(health<=0) return false;
        seen.insert({x,y});
        for(auto &dir:dirs){
            int newX=x+dir[0],newY=y+dir[1];
            if(newX>=0&&newX<m&&newY>=0&&newY<n&&!seen.count({newX,newY})){
                if(dfs(grid,health-grid[newX][newY],newX,newY,seen)) return dp[x][y][health]=true;
            }
        }
        seen.erase({x,y});
        return dp[x][y][health]=false;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // dfs with simple seen set of coords and at last if health >=1 return true
        // go in all 4 directions and if coords possible and not seen yet move to them
        // check if the coords are 0 or 1 if 1 reduce health , else do not and 
        // if in any 4 direction we get true then return true
        // else after all of the paths return false
        // for optimization add a 3d dp 
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(health+1,-1)));
        unordered_set<pair<int,int>,hash>seen;
        if(grid[0][0]==1) health--;//missed edge case
        return dfs(grid,health,0,0,seen);
    }
};