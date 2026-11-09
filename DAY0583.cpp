// 3619. Count Islands With Total Value Divisible by K
class Solution {
private:
    int m,n;
    vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    long long dfs(vector<vector<int>>& grid,vector<vector<bool>>& seen,int x,int y){
        seen[x][y]=true;
        long long sum = grid[x][y];
        int newX,newY;
        for(auto &dir:dirs){
            newX = dir[0] + x;
            newY = dir[1] + y;
            if(newX >= 0 && newX < m && newY >= 0 && newY < n && !seen[newX][newY] && grid[newX][newY] > 0){
                sum += dfs(grid,seen,newX,newY);
            }
        }
        return sum;
    }

    queue<pair<int,int>>q;
    long long bfs(vector<vector<int>>& grid,vector<vector<bool>>& seen,int i,int j){
        q.push({i,j});
        seen[i][j]=true;
        long long sum=0;
        int newX,newY;
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            sum += grid[x][y];
            for(auto &dir:dirs){
                newX = dir[0] + x;
                newY = dir[1] + y;
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && !seen[newX][newY] && grid[newX][newY] > 0){
                    seen[newX][newY]=true;
                    q.push({newX,newY});
                }
            }
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        // simple traversal and finding connected non zero numbers summing them up and returning the sum 
        // to check for the divisible by k condition can be done by both bfs and dfs.
        // time O(n*m) space O(n*m)
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>seen(m,vector<bool>(n,false));
        long long totalValue;
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] > 0 && !seen[i][j]){
                    // dfs
                    // totalValue = dfs(grid,seen,i,j);

                    // bfs
                    totalValue = bfs(grid,seen,i,j);

                    if(totalValue%k == 0) islands++;
                }
                seen[i][j]=true;
            }
        }
        return islands;
    }
};