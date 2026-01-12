// 926. Flip String to Monotone Increasing
class Solution {
private:
    vector<vector<int>>dp;
    int helper(string &s,int idx,char prev){
        if(idx==s.size()) return 0;
        if(dp[idx][prev-'0']!=-1) return dp[idx][prev-'0'];
        int cost=INT_MAX;
        if(prev=='0'){
            if(s[idx]=='0') cost=min(helper(s,idx+1,s[idx]),helper(s,idx+1,'1')+1);
            if(s[idx]=='1') cost=min(helper(s,idx+1,s[idx]),helper(s,idx+1,'0')+1);
        }
        if(prev=='1') {
            if(s[idx]=='0') cost=helper(s,idx+1,'1')+1;
            if(s[idx]=='1') cost=helper(s,idx+1,'1');
        }
        return dp[idx][prev-'0']=cost;
    }
public:
    int minFlipsMonoIncr(string s) {
        // either the string would end with 0 or 1
        // if the string so far is ended with zero get its cost and if its ending with one get its cost also
        // if the current elem is 0 so just carry forward the cost of ending with 0 if we keep it 0
        // else see whats better either to end the prev string with 0 or 1 and add +1 to it to make it end with 1
        // if the current elem is 1 then see whats better to end the prev string with 
        // else if we convert it to 0 then add +1 to the cost of ending the string with 0
        // int end0=0,end1=0;
        // for(char c:s){
        //     int new0=0,new1=0;
        //     if(c=='0'){
        //         new0=end0;
        //         new1=min(end0,end1)+1;
        //     }
        //     else{
        //         new0=end0+1;
        //         new1=min(end0,end1);
        //     }
        //     end0=new0;
        //     end1=new1;
        // }
        // return min(end0,end1);
        dp.resize(s.size(),vector<int>(2,-1));
        return helper(s,0,'0');
    }
};