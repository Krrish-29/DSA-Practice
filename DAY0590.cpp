// 190. Reverse Bits
class Solution {
public:
    int reverseBits(int n) {
        // move backward (left to right) for n
        // to make num starting with 0
        // if n%2 is 1 add 1 to num
        // and n is divided by 2 , and num is multiplied by 2 everytime
        // and to stop at 32 bit signed integer use i = 31 till i > 0 as well
        int num = 0 , i = 31;
        while(i > 0){
            if(n%2 == 1) num += 1;
            n /= 2;
            num *= 2;
            i--;
        }
        return num;
    }
};