// 3603. Minimum Cost Path with Alternating Directions II
class Solution {
private:
    vector<vector<long long>>grid;
    int row,col;
    long long getCost(vector<vector<int>>&waitCost,int i,int j){
        if(grid[i][j]!=-1) return grid[i][j];
        long long best=LLONG_MAX;
        if(i>0) best=min(best,getCost(waitCost,i-1,j));
        if(j>0) best=min(best,getCost(waitCost,i,j-1));
        if(best==LLONG_MAX) return grid[i][j]=waitCost[i][j]+(i+1)*(j+1);
        return grid[i][j]=best+waitCost[i][j]+(i+1)*(j+1);
    }
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        row=m;
        col=n;
        grid.resize(m,vector<long long>(n,-1));
        return getCost(waitCost,m-1,n-1)-waitCost[m-1][n-1]-waitCost[0][0];
    }
};