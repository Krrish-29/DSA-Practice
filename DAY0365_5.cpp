// 22. Generate Parentheses
class Solution {
private:
    vector<string>ans;
    void helper(int open,int close,int limit,string s){
        if(open==limit&&close==limit) {
            ans.push_back(s);
            return ;
        }
        if(open<limit){
            helper(open+1,close,limit,s+'(');
        }
        if(open>close){
            helper(open,close+1,limit,s+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return ans;
    }
};