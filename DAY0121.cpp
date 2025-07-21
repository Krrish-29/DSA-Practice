// 1957. Delete Characters to Make Fancy String
class Solution {
public:
    string makeFancyString(string s) {
        int size=s.size(),k=0,dup=0;
        for(int i=0;i<size;i++){
            s[k++]=s[i];
            if(i+2<size&&s[i]==s[i+1]&&s[i+1]==s[i+2]){
                while(i+2<size&&s[i]==s[i+1]&&s[i+1]==s[i+2]){
                    i++;
                    dup++;
                }
            }
        }
        return s.substr(0,size-dup);
    }
};