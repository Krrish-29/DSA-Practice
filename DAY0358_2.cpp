// 3871. Count Commas in Range II
class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999) return 0;
        long long comma=0;
        if(n>999) comma+=n-999;
        if(n>999999) comma+=n-999999;
        if(n>999999999) comma+=n-999999999;
        if(n>999999999999) comma+=n-999999999999;
        if(n>999999999999999) comma+=n-999999999999999;
        return comma;
    }
};