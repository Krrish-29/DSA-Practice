// 29. Divide Two Integers
class Solution {
    public:
        int divide(long dividend, long divisor) {
            if(divisor==1) return dividend;
            if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
            int sign=1,i=31,result=0;
            if((dividend<0)^(divisor<0)) sign=-1;
            dividend=abs(dividend);
            divisor=abs(divisor);
            while(--i>=0){
                if((dividend>>i)>=divisor){
                    result+=(1<<i);
                    dividend-=(divisor<<i);
                }
            }
            return sign*result;
        }
    };