// 921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string s) {
        // any time we get a ) when there is no ( left , then +1
        // and any ( left at the end 
        // only these parenthesis contribute to ans;

        // stack<char>stack;
        // for(char &c:s){
        //     if(!stack.empty() && stack.top()=='(' && c ==')') stack.pop();
        //     else stack.push(c);
        // }
        // return stack.size();
        int ans=0,open=0;
        for(char &c:s){
            if(c=='(') {
                open++;
            }
            else{ //closing
                if(open==0) ans++;
                else open--;
            }
        }
        return ans+open;
    }
};