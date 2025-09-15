// 1935. Maximum Number of Words You Can Type
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count=0;
        bool flag=true;
        for(int i=0;i<text.size();i++){
            flag=true;
            while(i<text.size()&&text[i]!=' '){
               if(brokenLetters.find(text[i])!=string::npos){ 
                   flag=false;
               }
                i++;
            }
            if(flag) count++;
        }
        return count;
    }
};