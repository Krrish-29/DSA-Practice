// 3307. Find the K-th Character in String Game II
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long n=1;
        int increment=0,i=0;
        while(true){
            n*=2;
            if(n>=k) break;    
            i++;
        }      
        for(i;i>=0&&n>1;i--){
            if(k>n/2){
                k-=n/2;
                increment+=operations[i];
            }
            n/=2;
        }
        return (char) (increment%26)+'a';
    }
};