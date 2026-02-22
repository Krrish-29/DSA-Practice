// 3849. Maximum Bitwise XOR After Rearrangement
class Solution {
public:
    string maximumXor(string s, string t) {
        int one=0,zero=0;
        for(char &ch:t){
            if(ch=='1') one++;
            else zero++;
        }
        t="";
        for(char &ch:s){
            if(ch=='1') {
                if(zero>0) {
                    t+='0';
                    zero--;
                }
                else {
                    t+='1';
                    one--;
                }
            }
            else{
                if(one>0) {
                    t+='1';
                    one--;
                }
                else {
                    t+='0';
                    zero--;
                }
            }
        }
        string xorStr;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[i]) xorStr+='0';
            else xorStr+='1';
        }
        return xorStr;
    }
};