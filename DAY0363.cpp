// 3567. Minimum Absolute Difference in Sliding Submatrix
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                vector<int>temp;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        temp.push_back(grid[x][y]);
                    }
                }
                sort(temp.begin(),temp.end());
                int minDiff=INT_MAX;
                for(int i=1;i<temp.size();i++){
                    if(temp[i]!=temp[i-1]) minDiff=min(minDiff,temp[i]-temp[i-1]);
                }
                ans[i][j]=minDiff==INT_MAX?0:minDiff;
            }
        }
        return ans;
    }
};