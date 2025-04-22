// 240. Search a 2D Matrix II
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row=matrix.size();
            int current_row=0,current_col=matrix[0].size()-1;
            while(current_row<row&&current_col>=0){
                if(matrix[current_row][current_col]==target) {
                    return true;
                }
                else if(matrix[current_row][current_col]>target){
                    current_col--;
                }
                else {
                    current_row++;
                }
            }
            return false;
        }
    };