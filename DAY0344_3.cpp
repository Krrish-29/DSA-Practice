// 1680. Concatenation of Consecutive Binary Numbers
class Solution {
public:
    int concatenatedBinary(int n) {
        long long num=0,MOD=1e9+7;
        // for(int i=1;i<=n;i++){
        //     bool start=false;
        //     for(int bit=17;bit>=0;bit--){
        //         if(i&(1<<bit)){
        //             start=true;
        //             num<<=1;
        //             num+=1;
        //         }
        //         else if(start){
        //             num<<=1;
        //         }
        //         num%=MOD;
        //     }
        // }
        for(int i=1;i<=n;i++){
            int bit;
            for(bit=17;bit>=0;bit--){
                if(i&(1<<bit)) break;
            }
            num=((num<<(bit+1))%MOD+i);
        }
        return (int)num;
    }
};