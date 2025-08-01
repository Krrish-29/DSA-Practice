// 12. Integer to Roman
class Solution {
private:
    string helper(int num){
        if(num<4) return "1";
        else if(num==4) return "IV";
        else if(num>4&&num<9) return "V"+string(num-5,'I');
        else if(num==9) return "IX";
        else if(num>=10&&num<50) return 
        else if(num>=1000) return string(num/1000,'M');
        else return "";
    }
public:
    string intToRoman(int num) {
        int base=1000;
        string answer;
        while(num>0){
            if(num/base>0){
                answer+=helper((num/base)*base);
            }
            num-=((num/base)*base);
            base/=10;
        }
        return answer;
    }
};