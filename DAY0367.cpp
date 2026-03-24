// 2906. Construct Product Matrix
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        // flatten the grid use suffix and prefix 
        int m=grid.size(),n=grid[0].size();
        const int MOD=12345;
        vector<int>flatten(m*n);
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flatten[idx]=grid[i][j];
                idx++;
            }
        }
        vector<long long>prefix(m*n);
        prefix[0]=flatten[0];
        for(int i=1;i<m*n;i++){
            prefix[i]=(prefix[i-1]*flatten[i])%MOD;
        }
        vector<long long>suffix(m*n);
        suffix[m*n-1]=flatten[m*n-1];
        for(int i=m*n-2;i>=0;i--){
            suffix[i]=(suffix[i+1]*flatten[i])%MOD;
        }
        for(int i=0;i<m*n;i++){
            long long left=(i==0?1:prefix[i-1]);
            long long right=(i==m*n-1?1:suffix[i+1]);
            grid[i/n][i%n]=(left*right)%MOD;
        }
        return grid;
    }
};