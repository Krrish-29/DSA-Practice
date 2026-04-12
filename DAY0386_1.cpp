// 3898. Find the Degree of Each Vertex
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int size=matrix.size();
        vector<int>ans(size,0);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(matrix[i][j]==1) ans[i]++;
            }
        }
        return ans;
    }
};