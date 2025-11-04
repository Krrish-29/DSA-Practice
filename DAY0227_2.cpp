// 3726. Remove Zeros in Decimal Representation
class Solution {
public:
    long long removeZeros(long long n) {
        long long ans=0,count=1;
        while(n>0){
            if(n%10>0) {
                ans=ans+count*(n%10);
                count*=10;
            }
            n/=10;
        }
        return ans;
    }
};