// 3821. Find Nth Smallest Integer With K One Bits
class Solution {
public:
    long long nthSmallest(long long n, int k) {
        vector<vector<long long>>nCr(50,vector<long long>(50,0));
        for(int i=0;i<50;i++){
            nCr[i][0]=1;
            for(int j=1;j<=i;j++){
                nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
            }
        }
        long long res=0;
        for(int i=49;i>=0&&k>=0;i--){
            long long count=0;
            if(i>=k) count+=nCr[i][k];
            if(n>count) {
                res=res|(1LL<<i);
                n-=count;
                k--;
            }
        }
        return res;
    }
};