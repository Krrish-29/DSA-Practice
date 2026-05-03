// 3918. Sum of Primes Between Number and Its Reverse
class Solution {
private:
    long long getPrimes(int limit){
        vector<bool>primes(limit+1,true);
        for(int i=2;i*i<=limit;i++){
            if(primes[i]){
                for(int j=i*i;j<=limit;j+=i){
                     primes[j]=false;   
                }
            }
        }
        long long count=0;
        for(int i=2;i<=limit;i++) {
            if(primes[i]) {
                count+=i;
            }
        }
        return count;
    }
public:
    int sumOfPrimesInRange(int n) {
        int start=n,end=0;
        while(n>0){
            end=end*10+n%10;
            n/=10;
        }
        return getPrimes(max(start,end))-getPrimes(min(start,end)-1);
    }
};