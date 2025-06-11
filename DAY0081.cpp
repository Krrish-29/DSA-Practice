// 54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
        vector<int>answer;
        while(left<=right&&top<=bottom){
            for(int col=left;col<=right;col++){
                answer.push_back(matrix[top][col]);
            }
            top++;
            for(int row=top;row<=bottom;row++){
                answer.push_back(matrix[row][right]);
            }
            right--;
            if(top<=bottom){
                for(int col=right;col>=left;col--){
                    answer.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            if(left<=right){
                for(int row=bottom;row>=top;row--){
                    answer.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        return answer;
    }
};