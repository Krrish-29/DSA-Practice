// 2249. Count Lattice Points Inside a Circle
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>coords;
        for(auto c:circles){
            int x=c[0],y=c[1],r=c[2];
            int minX=x-r,minY=y-r;
            int maxX=x+r,maxY=y+r;
            for(int i=minX;i<=maxX;i++){
                for(int j=minY;j<=maxY;j++){
                    if((x-i)*(x-i)+(y-j)*(y-j)<=(r*r)) coords.insert({i,j});
                }
            }
        }
        return coords.size();
    }
};