// 150. Evaluate Reverse Polish Notation
class Solution {
// private:
//     int stoi(string &s){
//         int num=0,sign=1,i=0;
//         if(s[i]=='-') {
//             sign=-1;
//             i++;
//         }
//         for(i;i<s.size();i++){
//             num=num*10+(s[i]-'0');
//         }
//         return num*sign;
//     }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stack;
        int op1,op2;
        for(string s:tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/") {
                op1=stack.top();stack.pop();
                op2=stack.top();stack.pop();
                if(s=="+") stack.push(op2+op1);
                else if(s=="-") stack.push(op2-op1);
                else if(s=="*") stack.push(op2*op1);
                else if(s=="/") stack.push(op2/op1);
            }
            else stack.push(stoi(s));
        }
        return stack.top();
    }
};