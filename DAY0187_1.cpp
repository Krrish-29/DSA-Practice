// 120. Triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height=triangle.size()-1;
        while(--height>=0){
            for(int i=triangle[height].size()-1;i>=0;i--){
                triangle[height][i]+=min(triangle[height+1][i],triangle[height+1][i+1]);
            }
        }
        return triangle[0][0];
    }
};