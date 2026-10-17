// 4070. Minimum Rotations to Dial a Number I
class Solution {
public:
    int minRotations(string s) {
        // either go from x to y or 10 - x to y (reverse)
        int sum=0,prev=0,current;
        for(char &c:s){
            current = c-'0';
            sum+= min(abs(current-prev),10-abs(current-prev));
            prev=current;
        }
        return sum;
    }
};