// 2939. Maximum Xor Product
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        // consider a^x as a single unit and same for b^x , a^x = a, b^x = b
        // if a and b ith bit is same, and 0 then x will have its ith bit as 1
        // for that to reflect do or of a and b with 1<<i
        // if they have different bit, then find the bigger number and check if its ith bit is set 
        // cause we need to make both numbers are close to each other for maximum product 
        // for that we need to sacrifice the ith bit of bigger number and give it to smaller number to close the gap
        // so we can to or with 1<<i for smaller number and xor with 1<<i for bigger number
        // also this is done from msb to lsb , and due to x < 2^n we can only access n-1 bits (and well as shift 1LL)
        for(int i=n-1;i>=0;i--){
            if((1&(a>>i)) == (1&(b>>i))) {
                if((1&(a>>i)) == 0) {
                    a|= (1LL<<i);
                    b|= (1LL<<i);
                }
            }else{
                if(a>b && (1&(a>>i))){
                    b|= (1LL<<i);
                    a^= (1LL<<i);
                }
                else if(b>a && (1&(b>>i))){
                    a|= (1LL<<i);
                    b^= (1LL<<i);
                }
            }
        }
        const int MOD = 1e9+7;
        return ((a%MOD)*(b%MOD))%MOD;
    }
};