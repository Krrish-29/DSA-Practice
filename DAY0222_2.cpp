// 2390. Removing Stars From a String
class Solution {
public:
    string removeStars(string s) {
        // stack<char>stack;
        // for(char ch :s){
        //     if(ch=='*') stack.pop();
        //     else stack.push(ch);
        // }
        // s.clear();
        // while(!stack.empty()){
        //     s.insert(s.begin(),stack.top());
        //     stack.pop();
        // }
        // return s;
        int i=0,j=0,size=s.size();
        for(j=0;j<size;j++){
            if(s[j]=='*'&&i>0){
                i--;
                continue;
            }
            s[i]=s[j];
            i++;
        }
        return s.substr(0,i);
    }
};