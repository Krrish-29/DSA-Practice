// 3908. Valid Digit Number
class Solution {
public:
    bool validDigit(int n, int x) {
        bool ans=false;
        while(n>=10){
            if(n%10==x) ans= true;
            n/=10;
        }
        if(n%10==x) return false;
        return ans;
    }
};