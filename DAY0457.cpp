// 3959. Check Good Integer
class Solution {
public:
    bool checkGoodInteger(int n) {
        int result=0,digit;
        while(n>0){
            digit=n%10;
            result+=(digit*digit)-digit;
            n/=10;
        }
        return result>=50;
    }
};