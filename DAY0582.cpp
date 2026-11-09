// 4092. Binary Digit Score
class Solution {
private:
    int setBits(int &num){
        int bits=0;
        for(int i=31;i>=0;i--){
            if( 1 & (num >> i) ) bits++;
        }
        return bits;
    }
public:
    int calculateScore(int a, int b) {
        a = setBits(a);
        b = setBits(b);
        return a >= b ? a*b : b/a;
    }
};