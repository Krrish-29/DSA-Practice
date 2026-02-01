// 3827. Count Monobit Integers
class Solution {
public:
    int countMonobit(int n) {
        int count=0;
        for(int x=0;x<=n;x++){
            int ones=0,zero=0;
            for(int i=0;i<10;i++){
                if((1<<i)>x) break;
                if(x&(1<<i)) ones++;
                else zero++;
            }
            if(ones==0||zero==0) count++;
        }
        return count;
    }
};