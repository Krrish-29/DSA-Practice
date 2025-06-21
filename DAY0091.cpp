// 59. Spiral Matrix II
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>answer(n,vector<int>(n,0));
        int left=0,right=n-1,top=0,bottom=n-1;
        int i=0;
        while(left<=right&&top<=bottom){
            for(int col=left;col<=right;col++){
                answer[top][col]=i+1;
                i++;
            }
            top++;
            for(int row=top;row<=bottom;row++){
                answer[row][right]=i+1;
                i++;
            }
            right--;
            if(top<=bottom){
                for(int col=right;col>=left;col--){
                    answer[bottom][col]=i+1;
                    i++;
                }
                bottom--;
            }
            if(left<=right){
                for(int row=bottom;row>=top;row--){
                    answer[row][left]=i+1;
                    i++;
                }
                left++;
            }
        }
        return answer;
    }
};