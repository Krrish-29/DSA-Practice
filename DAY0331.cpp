// 3495. Minimum Operations to Make Array Elements Zero
class Solution {
private:
    long long getCost(long long l,long long r){
        long long L=1,level=1,total=0;
        while(L<=r){
            long long R = 4*L-1;
            long long start=max(L,l);
            long long end=min(R,r);
            if(end>=start) total+=(end-start+1)*level;
            level++;
            L*=4;
        }
        return total;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long total=0;
        for(auto &query:queries){
            int l=query[0],r=query[1];
            total+=(getCost(l,r)+1)/2;
        }
        return total;
    }
};