// 134. Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size=gas.size();
        int prevGas=0,currGas=0,startPoint=-1;
        bool found=false;
        for(int i=0;i<size;i++){
            if(found){
                currGas+=(gas[i]-cost[i]);
                if(currGas<0){
                    found=false;
                    prevGas+=currGas;
                }
            }
            else if(gas[i]-cost[i]<0&&!found){
                prevGas+=(gas[i]-cost[i]);
            }
            else if(gas[i]-cost[i]>=0&&!found){
                currGas=(gas[i]-cost[i]);
                startPoint=i;
                found=true;
            }
        }
        return currGas+prevGas>=0?startPoint:-1;
    }
};