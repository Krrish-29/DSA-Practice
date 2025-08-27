// 3658. GCD of Odd and Even Sums
class Solution {
private:
    int gcd(int a,int b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        // return gcd(n*n,n*(n+1));
        return n;
    }
};