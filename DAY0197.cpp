// 417. Pacific Atlantic Water Flow
class Solution {
    int m,n;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<bool>>&ocean,int i,int j,vector<vector<int>>&heights){
        ocean[i][j]=true;
        for(auto d:dir){
            if(d[0]+i<0||d[0]+i>=m||d[1]+j<0||d[1]+j>=n||ocean[i+d[0]][j+d[1]]) continue;
            if(heights[i+d[0]][j+d[1]]<heights[i][j]) continue;

            dfs(ocean,i+d[0],j+d[1],heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<bool>>Pacific(m,vector<bool>(n,false));
        vector<vector<bool>>Atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) dfs(Pacific,i,0,heights);
        for(int j=0;j<n;j++) dfs(Pacific,0,j,heights); 
        for(int i=0;i<m;i++) dfs(Atlantic,i,n-1,heights);
        for(int j=0;j<n;j++) dfs(Atlantic,m-1,j,heights);

        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(Pacific[i][j]&&Atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};