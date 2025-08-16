// 3643. Flip Square Submatrix Vertically
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top=x,bottom=x+k-1,left=y,right=y+k;
        for(top;top<bottom;top++,bottom--){
            for(int j=left;j<right;j++){
                swap(grid[top][j],grid[bottom][j]);
            }
        }
        return grid;
    }
};