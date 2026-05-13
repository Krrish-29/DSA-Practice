// 1665. Minimum Initial Energy to Finish Tasks
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]-a[0]>b[1]-b[0];
        });
        // sort based on maxenergy gap 
        // since to solve greedly we need to find 
        // max energy gap so that smaller ones can be fit into it without need to increment the init energy
        int initEnergy=0,currEnergy=0;
        int actual=0,minimum=0;
        for(auto &task:tasks){
            actual=task[0],minimum=task[1];
            if(currEnergy>=minimum){
                currEnergy-=actual;
            }
            else{
                int change=minimum-currEnergy;
                currEnergy+=change;
                initEnergy+=change;
                currEnergy-=actual;
            }
        }
        return initEnergy;
    }
};