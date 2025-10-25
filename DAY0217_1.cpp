// 1716. Calculate Money in Leetcode Bank
class Solution {
public:
    int totalMoney(int n) {
        int weeks=n/7,days=n%7;
        return ((weeks*28)+((weeks-1)*weeks/2)*7)+(days*(days+1)/2)+(weeks*days);
    }
};