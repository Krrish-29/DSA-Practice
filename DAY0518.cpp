// 3622. Check Divisibility by Digit Sum and Product
class Solution {
public:
    bool checkDivisibility(int n) {
        int product=1,sum=0,num=n;
        while(n>0){
            product*=n%10;
            sum+=n%10;
            n/=10;
        }
        return num%(product+sum) == 0;
    }
};