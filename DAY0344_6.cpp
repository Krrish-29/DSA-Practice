// 91. Decode Ways
class Solution {
private:
    vector<int>dp;
    int recursion(string &s,int idx){
        int count=0;
        if(idx>=s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        else if(s[idx]=='1'){
            if(idx+1<s.size()) count+=recursion(s,idx+2);
            count+=recursion(s,idx+1);
        }
        else if(s[idx]=='2'){
            if(idx+1<s.size()&&s[idx+1]<='6') count+=recursion(s,idx+2);
            count+=recursion(s,idx+1);
        }
        else{
            count+=recursion(s,idx+1);
        }
        return dp[idx]=count;
    }
public:
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return recursion(s,0);
    }
};