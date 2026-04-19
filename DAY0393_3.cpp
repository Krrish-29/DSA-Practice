// 3905. Multi Source Flood Fill
class Solution {
private:
    struct hash{
        size_t operator()(const pair<int,int>&a) const {
            return (a.first*31*31)^(a.second*31);
        }  
    };
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        int totalColored=0;
        queue<pair<int,int>>q;
        for(auto &source:sources){
            if(grid[source[0]][source[1]]==0) totalColored++;
            grid[source[0]][source[1]]=max(grid[source[0]][source[1]],source[2]);
            q.push({source[0],source[1]});
        }
        if(totalColored==n*m) return grid;
        vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            unordered_set<pair<int,int>,hash>seen;
            for(int i=0;i<size;i++){
                auto coords=q.front();q.pop();
                int x=coords.first,y=coords.second;
                for(auto &dir:dirs){
                    int newX=x+dir[0],newY=y+dir[1];
                    if(newX>=0&&newX<n&&newY>=0&&newY<m){
                        if(grid[newX][newY]==0){
                            totalColored++;
                            q.push({newX,newY});
                            grid[newX][newY]=max(grid[newX][newY],grid[x][y]);
                            seen.insert({newX,newY});
                        }
                        else if(seen.count({newX,newY})){
                             grid[newX][newY]=max(grid[newX][newY],grid[x][y]);
                        }
                    }
                }
            }
            if(totalColored==n*m) return grid;
        }
        return grid;
    }
};