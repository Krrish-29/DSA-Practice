// 8. String to Integer (atoi)
class Solution {
    public:
        int myAtoi(string s) {
            string answer;
            long long int i=0,sign=1,value=0;
            while(s[i]==' '&&i<s.size()){
                i++;
            }
            if(s[i]=='+'||s[i]=='-'){
                sign=(s[i]=='-'?-1:+1);
                i++;
            }
            while(s[i]>='0'&&s[i]<='9'&&i<s.size()){
                answer+=s[i];
                i++;
            }
            for(int j=0;j<answer.length();j++){
                value=value*10+((answer.c_str()[j])-48);
                if (value > 2147483647){
                    return (sign == 1 ? 2147483647:-2147483648);
                }
            }
            return ((int)value)*sign;
        }
    };