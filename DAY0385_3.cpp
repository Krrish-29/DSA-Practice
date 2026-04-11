// 3896. Minimum Operations to Transform Array into Alternating Prime
class Solution {
private:
    vector<int>primes,nonPrimes;
    vector<bool>isPrime;
    void getPrimes(int limit){
        isPrime.resize(limit+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<=limit;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=limit;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        for(int i=0;i<=limit;i++){
            if(isPrime[i]) primes.push_back(i);
            else nonPrimes.push_back(i);
        }
    }
public:
    int minOperations(vector<int>& nums) {
        getPrimes(100009);
        int size=nums.size();
        int op=0;
        for(int i=0;i<size;i++){
            if(i%2==0&&!isPrime[nums[i]]){
                int idx=upper_bound(primes.begin(),primes.end(),nums[i])-primes.begin();
                if(idx>=0&&idx<primes.size()) op+=primes[idx]-nums[i];
            }
            if(i%2==1&&isPrime[nums[i]]){
                int idx=upper_bound(nonPrimes.begin(),nonPrimes.end(),nums[i])-nonPrimes.begin();
                if(idx>=0&&idx<nonPrimes.size()) op+=nonPrimes[idx]-nums[i];
            }
        }
        return op;
    }
};