// 20. Valid Parentheses
class Solution {
    public:
        vector<char>stack;
        void pop(){
            if (stack.size()==0) return ;
            stack.pop_back();
        }
        void  push(char c){
            stack.push_back(c);
        }
        char peek(){
            if(stack.size()==0) return ' ';
            return stack[stack.size()-1];
        }
        bool isValid(string s) {
            if (s.size() %2 ==1 )return false;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('||s[i]=='{'||s[i]=='['){
                    push(s[i]);
                }
                else if((s[i]==')'&&peek()=='(')||(s[i]=='}'&&peek()=='{')||(s[i]==']'&&peek()=='[')){
                    pop();
                }
                else{
                    return false;
                }
            }
            return stack.size()==0;
        }
    };