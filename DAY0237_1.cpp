// 2536. Increment Submatrices by One
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        //optimization -> mark +1 for r1 to r2 for c1 and -1 for c2+1 and then use simple prefix sum 
        int r1,c1,r2,c2;
        for(auto q:queries){
            r1=q[0],c1=q[1],r2=q[2],c2=q[3];
            for(int i=r1;i<=r2;i++){
                grid[i][c1]+=1;
                if(c2+1<n) grid[i][c2+1]+=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        return grid;
    }
};