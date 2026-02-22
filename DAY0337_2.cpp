// 3848. Check Digitorial Permutation
class Solution {
private:
    int getFactorial(int n){
        if(n==0) return 1;
        int res=1;
        for(int i=1;i<=n;i++){
            res*=i;
        }
        return res;
    }
public:
    bool isDigitorialPermutation(int n) {
        int number=n;
        vector<int>nums(10,0);
        vector<int>freq(10,0);
        while(n>0){
            nums[n%10]++;
            n=n/10;
        }
        int ans=0;
        for(int i=0;i<10;i++){
            ans+=nums[i]*getFactorial(i);
        }
        while(ans>0){
            freq[ans%10]++;
            ans=ans/10;
        }
        return nums==freq;
        
    }
};