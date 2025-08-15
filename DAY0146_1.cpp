// 342. Power of Four
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0&&1073741824%n==0&&((int)log2(n))%2==0) return true;
        return false;
    }
};