// 3370. Smallest Number With All Set Bits
class Solution {
public:
    int smallestNumber(int n) {
        int k=2;
        for(int i=1;i<31;i++){
            if(k>n) return k-1;
            if(k==n) return (k<<1)-1;
            k<<=1;
        }
        return 0;
    }
};