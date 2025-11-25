// 1015. Smallest Integer Divisible by K
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num=1;
        int len=1;
        if(k%10==2||k%10==5) return -1;
        while(num%k!=0&&len<k){
            num=(num*10+1)%k;
            len++;
        }
        if(num%k==0) return len;
        return -1;
    }
};