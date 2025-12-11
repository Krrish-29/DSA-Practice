// 3531. Count Covered Buildings
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // unordered_map<int,set<int>>xmap;
        // unordered_map<int,set<int>>ymap;
        // for(auto b:buildings){
        //     xmap[b[1]].insert(b[0]);
        //     ymap[b[0]].insert(b[1]);
        // }
        // int covered=0;
        // for(auto it:xmap){
        //     if(it.second.size()>=3){
        //         auto xstart=it.second.begin(),xend=it.second.end();
        //         xstart++;
        //         xend--;
        //         while(xstart!=xend){
        //             auto y=ymap[*xstart].find(it.first);
        //             if(y!=ymap[*xstart].begin()&&next(y)!=ymap[*xstart].end()) covered++;
        //             xstart++;
        //         }
        //     }
        // }
        // return covered;
        vector<int>maxRow(n+1,0);
        vector<int>minRow(n+1,n+1);
        vector<int>maxCol(n+1,0);
        vector<int>minCol(n+1,n+1);
        for(auto b:buildings){
            maxRow[b[1]]=max(maxRow[b[1]],b[0]);
            minRow[b[1]]=min(minRow[b[1]],b[0]);
            maxCol[b[0]]=max(maxCol[b[0]],b[1]);
            minCol[b[0]]=min(minCol[b[0]],b[1]);
        }
        int covered=0;
        for(auto b:buildings){
            if(b[0]<maxRow[b[1]]&&b[0]>minRow[b[1]]&&b[1]<maxCol[b[0]]&&b[1]>minCol[b[0]]) covered++;
        }
        return covered;
    }
};