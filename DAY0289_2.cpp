// 1975. Maximum Matrix Sum
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size(),smallest=INT_MAX;
        long long sum=0;
        bool negative=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]<0) negative=!negative;
                sum+=abs(matrix[i][j]);
                smallest=min(smallest,abs(matrix[i][j]));
            }
        }
        return negative==true?sum-2*smallest:sum;
    }
};