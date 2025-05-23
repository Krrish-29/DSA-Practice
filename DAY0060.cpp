// 73. Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        bool firstcol=false,firstrow=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    if(i==0) {firstrow=true;}
                    if(j==0) {firstcol=true;}
                    else{
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<col;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<row;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstcol){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        if(firstrow){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }
    }
};