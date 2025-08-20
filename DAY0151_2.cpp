// 3618. Split Array by Prime Indices
class Solution {
private:
    // vector<bool>isPrime;
    // void checkPrime(int n){
    //     isPrime.resize(n+1,true);
    //     isPrime[0]=isPrime[1]=false;
    //     for(int i=2;i*i<=n;i++){
    //         if(isPrime[i]){
    //             for(int j=i*i;j<=n;j+=i){
    //                 isPrime[j]=false;
    //             }
    //         }
    //     }
    // }
    bool isPrime(int n){
        if(n<=1) return false;
        if(n<=3) return true;
        if(n%2==0||n%3==0) return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0||n%(i+2)==0) return false;
        }
        return true;
    }
public:
    long long splitArray(vector<int>& nums) {
        int size=nums.size();
        // checkPrime(size);
        long long answer=0;
        for(int i=0;i<size;i++){
            if(isPrime(i)) answer-=nums[i];
            // if(isPrime[i]) answer-=nums[i];
            else answer+=nums[i];
        }
        return answer>=0?answer:answer*-1;
    }
};