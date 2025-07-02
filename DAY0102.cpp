// 367. Valid Perfect Square
class Solution {
public:
    bool isPerfectSquare(int num) {
        // for(int i=2;i<=num/2;i++){
        //     if(num%(i*i)==0) return true;
        // }
        // return false;
        if(num==1) return true;
        int left=2,right=num/2,middle;
        long temp ;
        while(left<=right){
            middle=left+(right-left)/2;
            temp =(long)middle*middle;
            if(temp==(long)num) return true;
            else if(temp>num) right=middle-1;
            else left=middle+1;
        }
        return false;
    }
};