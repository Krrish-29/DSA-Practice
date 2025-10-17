// 172. Factorial Trailing Zeroes
class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        int power=5;
        while(n/power>0){
            count+=n/power;
            power*=5;
        }
        return count;
    }
};