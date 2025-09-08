// 1317. Convert Integer to the Sum of Two No-Zero Integers
class Solution {
private:
    // bool checkZero(int n){
    //     if(n<=100&&n%10!=0) return true;
    //     else if(n>101&&n<=1000&&(n/10)%10!=0&&n%10!=0) return true;
    //     else if(n>1001&&n<=10000&&(n/100)%10!=0&&(n/10)%10!=0&&n%10!=0) return true;
    //     return false; 
    // }
    bool checkZero(int n){
        while(n>0){
            if(n%10==0) return false;
            n/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(checkZero(i)&&checkZero(n-i)) return {i,n-i};
        }
        return {0,0};
    }
};