// 3612. Process String with Special Operations I
class Solution {
public:
    string processStr(string s) {
        string ans;
        for(char &c:s){
            if(c<='z'&&c>='a') ans+=c;
            else if(c=='*'&&!ans.empty()) ans.pop_back();
            else if(c=='#') ans+=ans;
            else reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};