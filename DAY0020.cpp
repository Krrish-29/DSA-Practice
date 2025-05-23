// 48. Rotate Image
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            for(int i=0;i<matrix.size()/2;i++){
                swap(matrix[i],matrix[matrix.size()-1-i]);
            }
            for(int i=0;i<matrix.size();i++){
                for(int j=i+1;j<matrix[0].size();j++){
                    if(i!=j){
                        matrix[i][j]=matrix[i][j]^matrix[j][i];
                        matrix[j][i]=matrix[i][j]^matrix[j][i];
                        matrix[i][j]=matrix[i][j]^matrix[j][i];
                    }
                }
            }
        }
    };