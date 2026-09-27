// 1190. Reverse Substrings Between Each Pair of Parentheses
class Solution {
public:
    string reverseParentheses(string s) {
        // use a simple stack to keep items yet to be processed stored
        // now if we get a ( we push whatever we had earlier on to focus on item inside the current () 
        // that just started and reset the curr string 
        // if we get ) that means the item is fully in curr and we can reverse it 
        // and the this curr can be added with whatever string we were working on before this ()
        // started this stack approach separate all items in () and we can add them accordingly.
        stack<string>stack;
        string curr;
        for(char &c:s){
            if(c=='(') {
                stack.push(curr);
                curr="";
            }
            else if(c==')'){
                reverse(curr.begin(),curr.end());
                if(!stack.empty()) {
                    curr = stack.top() + curr;
                    stack.pop();
                }
            }else{
                curr+=c;
            }
        }
        return curr;
    }
};