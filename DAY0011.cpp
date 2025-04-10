// 50. Pow(x, n)
class Solution {
    public:
        double myPow(double x, int n) {
            if(n==0) return 1;
            double temp=1;
            if(n%2==1) temp=x;else if(n%2==-1) temp=1/x;
            if(n==1) return x; else if(n==-1) return 1/x;
            if(n>=INT_MAX) return x==1?1:(x==-1?(n%2==1?-1:1):0);else if(n<=INT_MIN) return x==1?1:(x==-1?(n%2==1?-1:1):0);
            return temp*myPow(x*x,n/2);
        }
    };