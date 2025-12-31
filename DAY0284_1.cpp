// 1926. Nearest Exit from Entrance in Maze
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>>dirs={{0,-1},{0,1},{1,0},{-1,0}};
        vector<vector<int>>dist(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        dist[entrance[0]][entrance[1]]=0;
        int x,y;
        while(!q.empty()){
            auto [i,j]=q.front();q.pop();
            for(auto dir:dirs){
                x=i+dir[0];
                y=j+dir[1];
                if(x>=0&&x<m&&y>=0&&y<n&&maze[x][y]=='.'&&dist[x][y]==-1){
                    dist[x][y]=dist[i][j]+1;
                    if(x==m-1||y==n-1||x==0||y==0) return dist[x][y];
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
};