// 282. Expression Add Operators
class Solution {
private:
    vector<string>ans;
    void backTrack(string &num,int idx,string currStrExpr,int target,long long prev,long long eval){
        if(idx==num.size()) {
            if(eval==target) ans.push_back(currStrExpr);
            return ;
        }
        for(int i=idx;i<num.size();i++){
            if(i!=idx&&num[idx]=='0') break;//remove leading zeros
            string currStr=num.substr(idx,i-idx+1);
            long long curr=stoll(currStr);
            if(idx==0) backTrack(num,i+1,currStr,target,curr,curr);
            else{
                backTrack(num,i+1,currStrExpr+"+"+currStr,target,curr,eval+curr);
                backTrack(num,i+1,currStrExpr+"-"+currStr,target,-1*curr,eval-curr);
                backTrack(num,i+1,currStrExpr+"*"+currStr,target,curr*prev,eval-prev+prev*curr);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        backTrack(num,0,"",target,0,0);
        return ans;
    }
};  