// 3536. Maximum Product of Two Digits
class Solution {
public:
    int maxProduct(int n) {
        int max=0,secmax=0;
        while(n>0){
            int digit=n%10;
            if(digit>=max) {
                secmax = max;
                max = digit;
            }
            else if(digit>secmax) {
                secmax = digit;
            }
            n/=10;
        }
        return max*secmax;
    }
};