// 120. Triangle
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            // int i,j,height=triangle.size(),widthCurrent=1;
            // for(i=1;i<height;i++){
            //     widthCurrent=triangle[i].size();
            //     for(j=0;j<widthCurrent;j++){
            //         if(j==0){
            //             triangle[i][j]+=triangle[i-1][0];
            //         }
            //         else if(j==triangle[i].size()-1){
            //             triangle[i][j]+=triangle[i-1][j-1];
            //         }
            //         else{
            //             triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            //         }
            //     }
            // }
            // int min_element=INT_MAX;
            // for(int x=0;x<triangle[i-1].size();x++){
            //     if(triangle[i-1][x]<min_element) min_element=triangle[i-1][x];
            // }
            // return min_element;
            int height=triangle.size()-1;
            while(--height>=0){
                for(int j=triangle[height].size()-1;j>=0;j--){
                        triangle[height][j]+=min(triangle[height+1][j+1],triangle[height+1][j]);
                    }
            }
            return triangle[0][0];
        }
    };