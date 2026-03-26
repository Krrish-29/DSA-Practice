// 3548. Equal Sum Grid Partition II
class Solution {
private:
    long long total;
    bool check(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        unordered_set<long long>seen;
        long long top=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                top+=grid[i][j];
                seen.insert(grid[i][j]);
            }
            long long bottom=total-top;
            if(top==bottom) return true;
            if(((top-bottom)==grid[0][0])||((top-bottom)==grid[0][n-1])||((top-bottom)==grid[i][0])) return true;
            if(i>0&&n>1&&seen.count(top-bottom)) return true;
        }
        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
            }
        }
        if(check(grid)) return true;
        reverse(grid.begin(),grid.end());
        if(check(grid)) return true;
        reverse(grid.begin(),grid.end());
        vector<vector<int>>grid1(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid1[j][i]=grid[i][j];
            }
        }
        if(check(grid1)) return true;
        reverse(grid1.begin(),grid1.end());
        if(check(grid1)) return true;
        return false;
        // // horizontal
        // unordered_set<long long>seen;
        // long long top=0;
        // for(int i=0;i<m-1;i++){
        //     for(int j=0;j<n;j++){
        //         top+=grid[i][j];
        //         seen.insert(grid[i][j]);
        //     }
        //     long long bottom=total-top;
        //     if(top==bottom) return true;
        //     if((top-bottom)==grid[0][0]||(top-bottom)==grid[0][n-1]||(top-bottom)==grid[i][0]) return true;
        //     if(i>0&&n>1&&seen.count(top-bottom)) return true;
        // }

        // seen.clear();
        // top=0;
        // for(int i=m-1;i>0;i--){
        //     for(int j=0;j<n;j++){
        //         top+=grid[i][j];
        //         seen.insert(grid[i][j]);
        //     }
        //     long long bottom=total-top;
        //     if(top==bottom) return true;
        //     if((top-bottom)==grid[m-1][0]||(top-bottom)==grid[m-1][n-1]||(top-bottom)==grid[i][0]) return true;
        //     if(i>0&&n>1&&seen.count(top-bottom)) return true;
        // }

        // // vertical
        // seen.clear();
        // long long left=0;
        // for(int j=0;j<n-1;j++){
        //     for(int i=0;i<m;i++){
        //         left+=grid[i][j];
        //         seen.insert(grid[i][j]);
        //     }
        //     long long right=total-left;
        //     if(left==right) return true;
        //     if((left-right)==grid[0][0]||(left-right)==grid[m-1][0]||(left-right)==grid[0][j]) return true;
        //     if(j>0&&m>1&&seen.count(left-right)) return true;
        // }

        // seen.clear();
        // left=0;
        // for(int j=n-1;j>0;j--){
        //     for(int i=0;i<m;i++){
        //         left+=grid[i][j];
        //         seen.insert(grid[i][j]);
        //     }
        //     long long right=total-left;
        //     if(left==right) return true;
        //     if((left-right)==grid[0][n-1]||(left-right)==grid[m-1][n-1]||(left-right)==grid[0][j]) return true;
        //     if(j>0&&m>1&&seen.count(left-right)) return true;
        // }

        // return false;
    }
};