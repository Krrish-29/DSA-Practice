// 3790. Smallest All-Ones Multiple
class Solution {
public:
    int minAllOneMultiple(int k) {
        long long num=1;
        for(int i=2;i<=k;i++){
            if((num*10+1)%k==0) return i;
            num=(num*10+1)%k;
        }
        return -1;
    }
};