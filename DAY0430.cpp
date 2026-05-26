// 1914. Cyclically Rotating a Grid
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        // simple but tricky to implement 
        // first thing to see it that the boundary values of rectangles is rotated so first implement
        // logic to rotate one rect and then update boundary till min(m/2,n/2) to rotate the grid once 
        // min(m/2,n/2) cause half or rows or cols will make the rect going over we would have flipped rects
        // next thing is since k<=1e9 but we can see that after moving around the perimeter of the rect 
        // numbers will repeat positions so we can do k%perimeter reducing to k<=50 and for each rect we 
        // can easily do so making this O(min(m/2,n/2)*k*m*n)Time O(1) Space 
        // m,n,k<=50

        // for the part of rotating save corners before shifting the whole side and then place back the
        // corner , try to draw !

        int m=grid.size(),n=grid[0].size();
        int rectangles=min(m/2,n/2);
        int top=0,bottom=m-1,left=0,right=n-1;
        for(int rec=0;rec<rectangles;rec++){
            int peri=2*((bottom-top)+(right-left));
            for(int repeat=0;repeat<k%peri;repeat++){
                int save1=grid[top][left];
                for(int j=left;j<right;j++){
                    grid[top][j]=grid[top][j+1];
                }
                int save2=grid[bottom][left];
                for(int i=bottom;i>top+1;i--){
                    grid[i][left]=grid[i-1][left];
                }
                grid[top+1][left]=save1;

                int save3=grid[bottom][right];
                for(int j=right;j>left+1;j--){
                    grid[bottom][j]=grid[bottom][j-1];
                }
                grid[bottom][left+1]=save2;

                for(int i=top;i<bottom;i++){
                    grid[i][right]=grid[i+1][right];
                }
                grid[bottom-1][right]=save3;
            }

            top++;bottom--;left++;right--;
        }
        return grid;
    } 
};