// 1979. Find Greatest Common Divisor of Array
class Solution {
private:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int maxEle=INT_MIN,minEle=INT_MAX;
        for(int &num:nums){
            maxEle=max(maxEle,num);
            minEle=min(minEle,num);
        }
        return gcd(maxEle,minEle);
    }
};