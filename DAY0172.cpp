// 2327. Number of People Aware of a Secret
class Solution {
private:
    int count(int currIndex,int &n,int &delay,int &forget,vector<int>&record){
        if(record[currIndex]!=-1) return record[currIndex];
        long total=(currIndex+forget-1>=n);
        for(int i=delay;i<forget;i++){
            if(currIndex+i>n) break;
            total=(total+count(currIndex+i,n,delay,forget,record))%(int)(1e9+7);
        }
        return record[currIndex]=total;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>record(n+1,-1);
        return count(1,n,delay,forget,record);
    }
};