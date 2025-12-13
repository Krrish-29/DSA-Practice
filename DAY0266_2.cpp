// 3770. Largest Prime from Consecutive Prime Sum
class Solution {
private:
    vector<bool> sieve(int n) {
        vector<bool>isPrime(n+1,true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
public:
    int largestPrime(int n) {
        int sum=0,i=0,ans=0;
        vector<bool>primes=sieve(500000);
        while(i<=n){
            if(primes[i]){
                sum+=i;
                if(sum>n) break;
                if(primes[sum]) ans=sum;
            }
            i++;
        }
        return ans;
    }
};