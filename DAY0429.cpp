// 1871. Jump Game VII
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // int size=s.size();
        // if(s[size-1]!='0') return false;
        // vector<bool>dp(size,false);
        // dp[size-1]=true;
        // for(int i=size-2;i>=0;i--){
        //     for(int j=i+minJump;j<=min(size-1,i+maxJump);j++){
        //         if(s[j]=='0'&&dp[j]) dp[i]=true;
        //     }
        // }
        // return dp[0];
        int size=s.size();
        queue<int>q;
        vector<bool>seen(size,false);
        q.push(0);
        seen[0]=true;
        int limit=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            if(x==size-1) return true;
            for(int i=max(limit,x+minJump);i<=min(size-1,x+maxJump);i++){
                if(s[i]=='0'&&!seen[i]) {
                    q.push(i);
                    seen[i]=true;
                }
            }
            // imp optimization cause it we rescan then we will get tle 
            // after the current x idx is seen and since we have scanned all the elems in its range 
            // next we need to see any new elem outside the range
            limit=min(size-1,x+maxJump);
        }
        return false;
    }
};