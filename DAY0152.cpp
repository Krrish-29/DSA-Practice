// 69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        // long long i=0;
        // while(i*i<=x){
        //     i++;
        // }
        // return i-1;
        long low=0,high=x,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid>x) high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};