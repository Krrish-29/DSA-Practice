// 3683. Earliest Time to Finish One Task
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int time=tasks[0][0]+tasks[0][1];
        for(auto vec:tasks){
            time=min(time,vec[0]+vec[1]);
        }
        return time;
    }
};