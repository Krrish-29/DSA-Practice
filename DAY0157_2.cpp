// 498. Diagonal Traverse
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>answer;
        int m=mat.size(),n=mat[0].size();
        int i=0,j=0,count=0;
        bool up=true;
        while(count<m*n){
            answer.push_back(mat[i][j]);
            count++;
            if(up){
                if(j==n-1){
                    i++;
                    up=false;
                }
                else if(i==0){
                    j++;
                    up=false;
                }
                else {
                    i--;
                    j++;
                }
            }
            else {
                if(i==m-1){
                    up=true;
                    j++;
                }
                else if(j==0){
                    i++;
                    up=true;
                }
                else {
                    i++;
                    j--;
                }
            }
        }
        return answer;
    }
};