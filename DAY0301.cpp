// 3809. Best Reachable Tower
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int idx=-1,size=towers.size();
        for(int i=0;i<size;i++){
            if(abs(towers[i][0]-center[0])+abs(towers[i][1]-center[1])<=radius){
                if(idx==-1) idx=i;
                else if (towers[i][2]>towers[idx][2]) idx=i;
                else if(towers[i][2]==towers[idx][2]){
                    if(towers[i][0]<towers[idx][0]) idx=i;
                    else if(towers[i][0]==towers[idx][0]&&towers[i][1]<towers[idx][1]) idx=i;
                }
            }
        }
        if(idx==-1) return {-1,-1};
        return {towers[idx][0],towers[idx][1]};
    }
};