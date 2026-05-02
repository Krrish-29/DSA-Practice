// 788. Rotated Digits
class Solution {
public:
    int rotatedDigits(int n) {
        int count=0,digit,num;
        bool flag=false;
        for(int i=1;i<=n;i++){
            num=i;
            flag=false;
            while(num>0){
                digit=num%10;
                if(digit==2||digit==5||digit==6||digit==9) flag=true;
                if(digit==3||digit==4||digit==7) {flag=false;break;}
                num/=10;
            }
            if(flag) count++;
        }
        return count;
    }
};