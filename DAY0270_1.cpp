// 3754. Concatenate Non-Zero Digits and Multiply by Sum I
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0,sum=0,ten=1;
        while(n!=0){
            if(n%10!=0){
                sum+=n%10;
                x=x+ten*(n%10);
                ten*=10;
            }
            n/=10;
        }
        return x*sum;
    }
};