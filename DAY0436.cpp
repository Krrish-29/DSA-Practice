// 3945. Digit Frequency Score
class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>freq(10,0);
        while(n>0){
            freq[n%10]++;
            n/=10;
        }
        int sum=0;
        for(int i=0;i<10;i++){
            sum+=i*freq[i];
        }
        return sum;
    }
};