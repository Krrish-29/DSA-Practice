// 3619. Count Islands With Total Value Divisible by K
class Solution {
private:
    int m,n;
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0) return 0;
        long long sum=grid[i][j];
        grid[i][j]=0;
        sum+=(dfs(grid,i+1,j)+dfs(grid,i,j+1)+dfs(grid,i-1,j)+dfs(grid,i,j-1));
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int count=0,curr_sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    curr_sum=dfs(grid,i,j);
                    if(curr_sum%k==0) count++;
                }
            }
        }
        return count;
    }
};