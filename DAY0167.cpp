// 2749. Minimum Operations to Make the Integer Zero
class Solution {
private:
    int countBits(long long n){
        int count=0;
        while(n){
            count+=n&1;
            n>>=1;
        }
        return count;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long num=num1;
        for(int i=1;i<61;i++){
            num-=num2;
            if(num<i) return -1;
            if(num>=0&&i>=countBits(num)) return i;
        }
        return -1;
    }
};