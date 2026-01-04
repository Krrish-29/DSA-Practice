// 3798. Largest Even Number
class Solution {
public:
    string largestEven(string s) {
        int size=s.size();
        while(size-1>=0&&s[size-1]!='2'){
            size--;
        }
        if (size==-1) return "";
        return s.substr(0,size);
    }
};