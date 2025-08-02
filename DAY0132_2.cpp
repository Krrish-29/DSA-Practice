// 58. Length of Last Word 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size=s.size(),len=0;
        bool firstLetter=false;
        for(int i=size-1;i>=0;i--){
            if(s[i]==' '&&firstLetter) break;
            else if(s[i]!=' '){
                len++; 
                firstLetter=true;
            }
        }
        return len;
    }
};