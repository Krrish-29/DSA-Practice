// 4039. Sum of Decoded Numbers
class Solution {
private:
    const int MOD=1e9+7;
    long long pow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        // simply do what the question says 
        // for each num get width by num%10 and d by num/10
        // then spliting d into x and y , for that make y=d 
        // and starting from base 10^15 till 1 divide and check when the number starts 
        // when it starts remove (y/base)*base from y and make x = x*10 + (y/base)
        // which removes the leftmost digit from y and adds it to x 
        // for each operation do width-- to keep track of how many digits needs to be shifted
        // then simply do x^y but due to numbers being large we need to do binary exponentiation
        long long sum=0,w,d,x,y;
        for(long long &num:nums){
            w = (num%10);
            d = (num/10);
            x = 0;
            y = d;
            bool start=false;
            for(long long base=1e15;base>0;base/=10){
                if(y/base>0) start = true;
                if(w==0) break;
                if(start){
                    x = ((x*10) + (y/base))%MOD;
                    y -= (y/base)*base;
                    w--;
                }
            }
            sum = (sum+pow(x,y))%MOD;
        }
        return sum;
    }
};