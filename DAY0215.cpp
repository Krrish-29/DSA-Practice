// 3461. Check If Digits Are Equal in String After Operations I
class Solution {
public:
    bool hasSameDigits(string s) {
        int size=s.size();
        while(size>2){
            for(int i=1;i<size;i++){
                s[i-1]=((s[i-1]-'0'+s[i]-'0')%10);
            }
            size--;
        }
        return s[0]==s[1];
    }
};