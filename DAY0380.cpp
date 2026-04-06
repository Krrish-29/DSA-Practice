// 874. Walking Robot Simulation
class Solution {
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
        int currDir=0;
        int x=0,y=0;
        int maxDist=0;
        unordered_set<pair<int,int>,pair_hash>set;
        for(auto &obs:obstacles){
            set.insert({obs[0],obs[1]});
        }
        for(int &command:commands){
            if(command<0){
                if(command==-1) currDir=(currDir+1)%4;
                else currDir=(currDir-1+4)%4;
            }
            else{
                for(int i=0;i<command;i++){
                    if(set.find({x+dirs[currDir][0],y+dirs[currDir][1]})!=set.end()) break;
                    x+=dirs[currDir][0];
                    y+=dirs[currDir][1];
                }
                maxDist=max(maxDist,x*x+y*y);
            }
        }
        return maxDist;
    }
};