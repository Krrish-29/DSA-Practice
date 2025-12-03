// 1513. Number of Substrings With Only 1s
class Solution {
public:
    int numSub(string s) {
        int size=s.size(),count=0;
        const int MOD=1e9+7;
        for(int i=0;i<size;i++){
            int j=i;
            while(i<size&&s[i]=='1') i++;
            count=count+((j-i)*1LL*(j-i-1)/2)%MOD;
        }
        return count%MOD;
    }
};