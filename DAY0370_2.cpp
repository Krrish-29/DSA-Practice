// 3212. Count Submatrices With Equal Frequency of X and Y
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // simply put just get the x and y count at each index using prefix and check 
        int m=grid.size(),n=grid[0].size();
        vector<vector<pair<int,int>>>map(m,vector<pair<int,int>>(n));// x count , y count
        int count=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]=='X') map[i][0]={1,0};
            if(grid[i][0]=='Y') map[i][0]={0,1};
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]=='X') map[i][j]={map[i][j-1].first+1,map[i][j-1].second};
                else if(grid[i][j]=='Y') map[i][j]={map[i][j-1].first,map[i][j-1].second+1};
                else map[i][j]=map[i][j-1];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                map[i][j]={map[i-1][j].first+map[i][j].first,map[i-1][j].second+map[i][j].second};
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(map[i][j].first>0&&map[i][j].first==map[i][j].second) count++;
            }
        }
        return count;
    }
};