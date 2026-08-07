// 3345. Smallest Divisible Digit Product I
class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int num=n,product=1;
            while(num>0){
                product*=(num%10);
                num/=10;
            }
            if(product%t==0) break;
            n++;
        }
        return n;
    }
};