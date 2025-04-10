// 13. Roman to Integer
class Solution {
    public:
        int checkvalue(char c){
            int x=0;
            if(c=='I') x= 1;
            if(c=='V') x= 5;
            if(c=='X') x= 10;
            if(c=='L') x= 50;
            if(c=='C') x= 100;
            if(c=='D') x= 500;
            if(c=='M') x= 1000;
            return x;
        }
        int romanToInt(string s) {
            int value=0,x,y=checkvalue(s[0]);
            for(int i=1;i<s.length();i++){
                x=checkvalue(s[i]);
                if(y>=x){
                    value+=y;
                }
                else{
                    value-=y;
                }
                y=x;
            }
            value+=y;
            return value;
        }
};