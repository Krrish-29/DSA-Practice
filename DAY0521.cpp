// 4024. Nearest Available Drone
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx=-1,size=drones.size(),x,y,currMdist=INT_MAX;
        for(int i=0;i<size;i++){
            x = abs(target[0]-drones[i][0]);
            y = abs(target[1]-drones[i][1]);
            if(x+y > drones[i][2]) continue;
            if(x+y<currMdist) {
                idx=i;
                currMdist=x+y;
            }
        }
        return idx;
    }
};