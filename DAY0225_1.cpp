// 2257. Count Unguarded Cells in the Grid
class Solution {
private:
struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // unordered_map<pair<int,int>,int,pair_hash>map;
        unordered_map<pair<int,int>,int,pair_hash>guard;
        unordered_map<pair<int,int>,int,pair_hash>wall;
        for(auto it:guards){
            guard[{it[0],it[1]}]++;
        }
        for(auto it:walls){
            wall[{it[0],it[1]}]++;
        }
        // for(auto it:guards){
        //     int x=it[0],y=it[1];
        //     for(int i=y+1;i<n;i++){
        //         if(guard.find({x,i})!=guard.end()||wall.find({x,i})!=wall.end()) break;
        //         map[{x,i}]++;
        //     }
        //     for(int i=y-1;i>=0;i--){
        //         if(guard.find({x,i})!=guard.end()||wall.find({x,i})!=wall.end()) break;
        //         map[{x,i}]++;
        //     }
        //     for(int j=x+1;j<m;j++){
        //         if(guard.find({j,y})!=guard.end()||wall.find({j,y})!=wall.end()) break;
        //         map[{j,y}]++;
        //     }
        //     for(int j=x-1;j>=0;j--){
        //         if(guard.find({j,y})!=guard.end()||wall.find({j,y})!=wall.end()) break;
        //         map[{j,y}]++;
        //     }
        // }
        // return m*n-guard.size()-wall.size()-map.size();
        vector<vector<bool>>seen(m,vector<bool>(n,false));
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto it:guards){
            int x=it[0],y=it[1];
            for(int d=0;d<4;d++){
                int nx=x,ny=y;
                while(true){
                    nx+=dir[d][0];
                    ny+=dir[d][1];
                    if(nx<0||nx>=m||ny<0||ny>=n) break;
                    if(guard.find({nx,ny})!=guard.end()||wall.find({nx,ny})!=wall.end()) break;
                    seen[nx][ny]=true;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(guard.find({i,j})==guard.end()&&wall.find({i,j})==wall.end()&&!seen[i][j]) count++;
            }
        }
        return count;
    }
};