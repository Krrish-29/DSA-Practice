// 3070. Count Submatrices with Top-Left Element and Sum Less Than k
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // simply put just get the sum at a index which includes the submatrix elems till the top left and then check
        int m=grid.size(),n=grid[0].size();
        long long sum=0;
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<=k) count++;
            }
        }
        return count;
    }
};