// 796. Rotate String
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int size=s.size();
        s+=s;
        for(int i=0;i<size;i++){
            if(goal==s.substr(i,size)) return true;
        }
        return false;
    }
};