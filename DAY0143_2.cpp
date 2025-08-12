// 2810. Faulty Keyboard
class Solution {
public:
    void reverse(string &s){
        int size=s.size();
        char temp;
        for(int i=0;i<size/2;i++){
            temp=s[i];
            s[i]=s[size-1-i];
            s[size-1-i]=temp;
        }
    }
    string finalString(string s) {
        string temp;
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]=='i'){
                reverse(temp);
            }
            else{
                temp+=s[i];
            }
        }
        return temp;
    }
};