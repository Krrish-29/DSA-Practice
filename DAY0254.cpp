// 2141. Maximum Running Time of N Computers
class Solution {
private:
    bool good(long long target,vector<int>&batteries,int & n){
        long long conti=0;
        for(long long b:batteries) conti+=min(b,target);
        return conti>=n*target;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // assume lowest time u can get is 1 and highest time sum(batteries)/n
        // binary search on time to get the best avg time 
        // consider a avg time mid=(right+left+1)/2 assuming all batteries can provide this much 
        // time if the contribution off all batteries conti+=min(b,target) exceeds the n*target then 
        // we can have a higher avg value of time and if not then lower avg time 
        long long left=1,right=0,mid;
        for(int b:batteries) right+=b;
        right/=n;
        while(left<right){
            mid=(right+left+1)/2;
            if(good(mid,batteries,n)){
                left=mid;
            }
            else right=mid-1;
        }
        return left;
    }
};