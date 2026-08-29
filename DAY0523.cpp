// 4020. Elevator Requests I
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int current=0,time=0;
        for(int &req:requests){
            time+=abs(current-req);
            current=req;
        }
        return time;
    }
};