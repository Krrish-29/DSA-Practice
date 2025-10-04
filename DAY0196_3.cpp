// 22. Generate Parentheses
class Solution {
private:
    void dfs(int open,int close,string &current,vector<string>&answer){
        if(open==0&&close==0){
            answer.push_back(current);
            return ;
        }
        if(open>0){
            current.push_back('(');
            dfs(open-1,close,current,answer);
            current.pop_back();
        }
        if(close>open){
            current.push_back(')');
            dfs(open,close-1,current,answer);
            current.pop_back();
        }
    } 
public:
    vector<string> generateParenthesis(int n) {
        vector<string>answer;
        string current;
        dfs(n,n,current,answer);
        return answer;
    }
};