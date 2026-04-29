// 71. Simplify Path
class Solution {
public:
    string simplifyPath(string path) {
        // int size=path.size();
        // string temp;
        // vector<string>str;
        // for(int i=0;i<size;i++){
        //     if(path[i]=='/') {
        //         if(temp==".."){
        //             if(str.size()!=0) str.pop_back();
        //         }
        //         else if(temp.size()!=0&&temp!=".") str.push_back(temp);
        //         temp="";
        //         continue;
        //     }
        //     temp+=path[i];
        // }
        // if(temp==".."){
        //     if(str.size()!=0) str.pop_back();
        // }
        // else if(temp.size()!=0&&temp!=".") str.push_back(temp);

        // if(str.size()==0) return "/";

        // string ans;
        // for(int i=0;i<str.size();i++){
        //     ans+=("/"+str[i]);
        // }
        // return ans;


        int size=path.size();
        string temp;
        stack<string>stack;
        string ans;
        for(int i=0;i<size;i++){
            if(path[i]=='/') {
                if(temp==".."){
                    if(!stack.empty()) stack.pop();
                }
                else if(temp.size()!=0&&temp!=".") {
                    stack.push(temp);
                }
                temp="";
                continue;
            }
            temp+=path[i];
        }
        if(temp==".."){
            if(!stack.empty()) stack.pop();
        }
        else if(temp.size()!=0&&temp!=".") {
            stack.push(temp);
        }
        if(stack.empty()) return "/";
        while(!stack.empty()){
            ans="/"+stack.top()+ans;
            stack.pop();
        }
        return ans;
    }
};