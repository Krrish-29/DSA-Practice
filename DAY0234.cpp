// 474. Ones and Zeroes
class Solution {
private:
    vector<vector<vector<int>>>grid;
    int rec(vector<string>&strs,int m,int n,int index){
        if(strs.size()==index) return 0;
        if(grid[m][n][index]!=-1) return grid[m][n][index];
        int newM=m,newN=n,take=0,skip=rec(strs,m,n,index+1);
        for(int i=0;i<strs[index].size();i++){
            if(strs[index][i]=='0') newM--;
            else newN--;
        }
        if(newM>=0&&newN>=0) take=1+rec(strs,newM,newN,index+1);
        return grid[m][n][index]=max(skip,take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // top-down
        // grid.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        // return rec(strs,m,n,0);

        // bottom-up
        vector<vector<int>>table(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();i++){
            int one=0,zero=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') zero++;
                else one++;
            }
            for(int x=m;x>=zero;x--){
                for(int y=n;y>=one;y--){
                    table[x][y]=max(table[x][y],1+table[x-zero][y-one]);
                }
            }
        }
        return table[m][n];
    }
};