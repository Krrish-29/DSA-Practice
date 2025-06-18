// 150. Evaluate Reverse Polish Notation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // stack<int>stack;
        // int size=tokens.size();
        // for(int i=0;i<size;i++){
        //     if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
        //         int op2=stack.top();
        //         stack.pop();
        //         int op1=stack.top();
        //         stack.pop();
        //         if(tokens[i]=="+") stack.push(op1+op2);
        //         if(tokens[i]=="-") stack.push(op1-op2);
        //         if(tokens[i]=="*") stack.push(op1*op2);
        //         if(tokens[i]=="/") stack.push(op1/op2);
        //     }
        //     else{
        //         stack.push(stoi(tokens[i]));
        //     }
        // }
        // return stack.top();
        vector<int>stack;
        int size=tokens.size();
        for(int i=0;i<size;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int op2=stack.back();
                stack.pop_back();
                int op1=stack.back();
                stack.pop_back();
                if(tokens[i]=="+") stack.push_back(op1+op2);
                if(tokens[i]=="-") stack.push_back(op1-op2);
                if(tokens[i]=="*") stack.push_back(op1*op2);
                if(tokens[i]=="/") stack.push_back(op1/op2);
            }
            else{
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack.front();
    }
};