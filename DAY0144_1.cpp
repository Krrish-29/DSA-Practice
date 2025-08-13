// 326. Power of Three
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n>0&&n<1162261468&&1162261467%n==0) return true;
        return false;
    }
};