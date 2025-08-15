// 779. K-th Symbol in Grammar
class Solution {
public:
    int kthGrammar(int n, int k) {
        // 0
        // 0 1
        // 0 1 1 0
        // 01 10 10 01
        // 0110 1001 1001 0110
        if(n==0) return 0;
        k--;
        int size,shift=0;
        for(int i=n-1;i>=0;i--){
            size=(1<<i);
            if(k>=size/2){
                shift++;
                k-=(size/2);
            }
        }
        return shift%2==0?1:0;
    }
};