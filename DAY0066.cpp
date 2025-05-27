// 2894. Divisible and Non-divisible Sums Difference
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum=0;
        while(n){
            if(n%m==0) totalSum-=n;
            else totalSum+=n;
            n--;
        }
        return totalSum;
    }
};