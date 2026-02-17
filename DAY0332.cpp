// 1504. Count Submatrices With All Ones
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int count=0;
        for(int start=0;start<m;start++){
            vector<int>temp(n,1);
            for(int end=start;end<m;end++){
                for(int j=0;j<n;j++){
                    temp[j]=temp[j]&mat[end][j];
                }
                int consecutive=0;
                for(int i=0;i<n;i++){
                    if(temp[i]==0) consecutive=0;
                    else consecutive++;
                    count+=consecutive;
                }
            }
        }
        return count;
    }
};