// 3870. Count Commas in Range
class Solution {
public:
    int countCommas(int n) {
        string num=to_string(n);
        if(num.size()<=3) return 0;
        int comma=0;
        if(n>999) comma+=n-999;
        return comma;
    }
}; 