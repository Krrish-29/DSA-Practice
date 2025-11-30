// 778. Swim in Rising Water
class Solution {
struct Compare{
    bool operator()(const vector<int>&a,const vector<int>&b){
        return a[0]>b[0];
    }
};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<vector<int>,vector<vector<int>>,Compare>pq;
        pq.push({grid[0][0],0,0});
        int time,x,y;
        while(!pq.empty()){
            auto info=pq.top();
            pq.pop();
            time=info[0],x=info[1],y=info[2];
            if(visited[x][y]) continue;
            visited[x][y]=true;
            if(x==n-1&&y==n-1) return time;
            for(auto d:dir){
                if(x+d[0]<0||x+d[0]>=n||y+d[1]<0||y+d[1]>=n||visited[x+d[0]][y+d[1]]) continue;
                pq.push({max(grid[x+d[0]][y+d[1]],time),x+d[0],y+d[1]});
            }
        }
        return -1;
    }
};