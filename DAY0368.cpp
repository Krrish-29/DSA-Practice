// 3546. Equal Sum Grid Partition I
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // vector<long long>horizontal(m,0);
        // vector<long long>vertical(n,0);

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         horizontal[i]+=grid[i][j];
        //         vertical[j]+=grid[i][j];
        //     }
        // }
        // long long left=0,right=0;
        // for(int i=0;i<m;i++){
        //     right+=horizontal[i];
        // }
        // for(int i=0;i<m;i++){
        //     left+=horizontal[i];
        //     right-=horizontal[i];
        //     if(left==right) return true;
        // }
        // left=0,right=0;
        // for(int i=0;i<n;i++){
        //     right+=vertical[i];
        // }
        // for(int i=0;i<n;i++){
        //     left+=vertical[i];
        //     right-=vertical[i];
        //     if(left==right) return true;
        // }
        // return false;


        // similar appraoch 
        long long total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
            }
        }
        long long top=0,left=0;
        for(int i=0;i<m-1;i++){// do this till m-1 , m will lead to total sum 
            for(int j=0;j<n;j++){
                top+=grid[i][j];
            }
            if(top*2==total) return true;
        }
        for(int j=0;j<n-1;j++){
            for(int i=0;i<m;i++){
                left+=grid[i][j];
            }
            if(left*2==total) return true;
        }
        return false;
    }
};