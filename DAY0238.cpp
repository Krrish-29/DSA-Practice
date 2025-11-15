// 394. Decode String
class Solution {
public:
    string decodeString(string s) {
        stack<char>stack;
        int size=s.size();
        string str;
        for(int i=0;i<size;i++){
            if(s[i]==']'){
                string temp;
                while(!stack.empty()&&stack.top()!='['){
                    temp.insert(temp.begin(),stack.top());
                    stack.pop();
                }
                stack.pop();
                int num=0,ten=1;
                while(!stack.empty()&&stack.top()<='9'&&stack.top()>='0'){
                    num+=(stack.top()-'0')*ten;
                    ten*=10;
                    stack.pop();
                }
                string repeat;
                for(int i=0;i<num;i++){
                    repeat+=temp;
                }
                for(char c:repeat) stack.push(c);
            }   
            else{
                stack.push(s[i]);
            }
        }
        while(!stack.empty()){
            str.insert(str.begin(),stack.top());
            stack.pop();
        }
        return str;
    }
};