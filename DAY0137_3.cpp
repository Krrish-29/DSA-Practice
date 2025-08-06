// 304. Range Sum Query 2D - Immutable
class NumMatrix {
private:
    vector<vector<int>>sum;
    int m,n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        sum.resize(m,vector<int>(n,0));
        sum=matrix;
        for(int i=m-1;i>=0;i--){   
            for(int j=n-1;j>=0;j--){
                if(i+1<m) sum[i][j]+=sum[i+1][j];
                if(j+1<n) sum[i][j]+=sum[i][j+1];
                if(i+1<m&&j+1<n) sum[i][j]-=sum[i+1][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total=sum[row1][col1];
        if(col2+1<n) total-=sum[row1][col2+1];
        if(row2+1<m) total-=sum[row2+1][col1];
        if(row2+1<m&&col2+1<n) total+=sum[row2+1][col2+1];
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */